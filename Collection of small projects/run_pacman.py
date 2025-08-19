import pygame
import sys
import time
import random

SCREEN_WIDTH = 400
SCREEN_HEIGHT = 400
TILE_SIZE = 20


# 맵: 0=빈공간, 1=벽, 2=먹이, 3=유령
level_map = [
    [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1],
    [1,2,2,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,2,1],
    [1,0,1,1,1,0,1,0,0,0,1,0,0,0,1,0,1,1,0,1],
    [1,0,2,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,0,1],
    [1,0,1,1,1,0,1,0,0,0,1,0,0,0,1,0,1,1,0,1],
    [1,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,2,0,3,1],
    [1,2,1,1,1,0,1,0,0,0,1,0,0,0,1,0,1,1,2,1],
    [1,0,2,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,0,1],
    [1,0,1,1,1,0,1,0,0,0,1,0,0,0,1,0,1,1,0,1],
    [1,2,2,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,2,1],
    [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
]

class Wall:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.width = TILE_SIZE
        self.height = TILE_SIZE
        self.color = (0,0,255)

    def draw(self, screen):
        pygame.draw.rect(screen, self.color, (self.x, self.y, self.width, self.height))

class Pellet:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.radius = 5
        self.color = (255,255,0)

    def draw(self, screen):
        pygame.draw.circle(screen, self.color, (self.x+self.radius, self.y+self.radius), self.radius)

class Ghost:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.width = TILE_SIZE
        self.height = TILE_SIZE
        self.color = (255,0,0)
        self.direction = random.choice([(1,0), (-1,0), (0,1), (0,-1)])

    def update(self, walls):
        # TODO: 유령 이동 로직 (간단히 랜덤하게 방향 전환하거나 벽에 막히면 방향 바꾸기)
        if(random.random() > 0.9):
            move_array = []
            if self.direction[0] == 1 or self.direction[0] == -1:
              move_array.append((0, 1))
              move_array.append((0, -1))
            elif self.direction[1] == 1 or self.direction[1] == -1:
              move_array.append((1, 0))
              move_array.append((-1, 0))
            self.direction = random.choice(move_array)
        for wall in walls:
          if (self.x + self.direction[0] + self.width > wall.x) and (self.x + self.direction[0] < wall.x + wall.width) and (self.y + self.direction[1] + self.height > wall.y) and (self.y + self.direction[1] < wall.y + wall.height):
            self.direction = random.choice([(1,0), (-1,0), (0,1), (0,-1)])
            return
        self.x += self.direction[0] * 2
        self.y += self.direction[1] * 2
        pass

    def draw(self, screen):
        pygame.draw.rect(screen, self.color, (self.x, self.y, self.width, self.height))

class Maze:
    def __init__(self, level_map):
        self.walls = []
        self.pellets = []
        self.ghosts = []
        self.parse_map(level_map)

    def parse_map(self, level_map):
        rows = len(level_map)
        cols = len(level_map[0])
        for r in range(rows):
            for c in range(cols):
                tile = level_map[r][c]
                x = c * TILE_SIZE
                y = r * TILE_SIZE
                if tile == 1:
                    self.walls.append(Wall(x,y))
                elif tile == 2:
                    self.pellets.append(Pellet(x,y))
                elif tile == 3:
                    self.ghosts.append(Ghost(x,y))

    def draw(self, screen):
        for w in self.walls:
            w.draw(screen)
        for p in self.pellets:
            p.draw(screen)
        for g in self.ghosts:
            g.draw(screen)

class Player:
    def __init__(self):
        self.width = TILE_SIZE
        self.height = TILE_SIZE
        self.x = TILE_SIZE
        self.y = TILE_SIZE
        self.color = (255,255,0)
        self.speed = 4

    def handle_input(self, keys, walls):
        dx, dy = 0,0
        if keys[pygame.K_LEFT]:
            dx = -self.speed
        elif keys[pygame.K_RIGHT]:
            dx = self.speed
        elif keys[pygame.K_UP]:
            dy = -self.speed
        elif keys[pygame.K_DOWN]:
            dy = self.speed

        # TODO: 벽 충돌 체크 후 이동
        # 이동할 위치가 벽과 겹치지 않으면 self.x, self.y 갱신
        for wall in walls:
          if (self.x + dx + self.width > wall.x) and (self.x + dx < wall.x + wall.width) and (self.y + dy + self.height > wall.y) and (self.y + dy < wall.y + wall.height):
            return
        self.x += dx
        self.y += dy
    def eat_pellet(self, pellets):
        # TODO: 플레이어가 펠릿 먹기 (플레이어와 펠릿 충돌 시 해당 펠릿 제거)
        for pellet in reversed(pellets):
          closet_x = max(self.x, min(pellet.x, self.x + self.width))
          closet_y = max(self.y, min(pellet.y, self.y + self.height))

          if(pow(pellet.x - closet_x, 2) + pow(pellet.y - closet_y, 2) <= pow(pellet.radius, 2)):
            pellets.remove(pellet)
        pass

    def draw(self, screen):
        pygame.draw.rect(screen, self.color, (self.x, self.y, self.width, self.height))

class Game:
    def __init__(self):
        pygame.init()
        self.screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
        pygame.display.set_caption("Pac-Man Simplified")
        self.clock = pygame.time.Clock()
        self.running = True

        self.maze = Maze(level_map)
        self.player = Player()

    def run(self):
        while self.running:
            self.handle_events()
            self.update()
            self.draw()
            self.clock.tick(60)

        pygame.quit()
        sys.exit()

    def handle_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.running = False

    def update(self):
        keys = pygame.key.get_pressed()
        self.player.handle_input(keys, self.maze.walls)

        # 유령 업데이트
        for g in self.maze.ghosts:
            g.update(self.maze.walls)

        # 펠릿 먹기 체크
        self.player.eat_pellet(self.maze.pellets)

        # 승리 조건: 모든 펠릿 먹었을 때
        if len(self.maze.pellets) == 0:
            self.game_win()

        # 패배 조건: 유령과 충돌
        # TODO: 유령과 플레이어 충돌 시 game_over()
        for ghost in self.maze.ghosts:
          if (self.player.x + self.player.width > ghost.x) and (self.player.x < ghost.x + ghost.width) and (self.player.y + self.player.height > ghost.y) and (self.player.y < ghost.y + ghost.height):
            self.game_over()
    def draw(self):
        self.screen.fill((0,0,0))
        self.maze.draw(self.screen)
        self.player.draw(self.screen)
        pygame.display.flip()

    def game_over(self):
        font = pygame.font.SysFont(None, 50)
        text = font.render("Game Over!", True, (255,0,0))
        self.screen.blit(text, (SCREEN_WIDTH//2 - 100, SCREEN_HEIGHT//2 - 25))
        pygame.display.flip()
        time.sleep(2)
        self.running = False

    def game_win(self):
        font = pygame.font.SysFont(None, 50)
        text = font.render("You Win!", True, (0,255,0))
        self.screen.blit(text, (SCREEN_WIDTH//2 - 80, SCREEN_HEIGHT//2 - 25))
        pygame.display.flip()
        time.sleep(2)
        self.running = False

if __name__ == "__main__":
    game = Game()
    game.run()
