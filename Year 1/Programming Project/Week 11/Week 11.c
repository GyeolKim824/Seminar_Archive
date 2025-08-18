#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/*

#define N 10
#define TRUE 1
#define FALSE 0

typedef int element;
element visited[N] = { 0 };
typedef struct StackType {
	int stack[N];
	int top;
}StackType;

void initStack(StackType* S) {
	S->top = -1;
}

int isStackEmpty(StackType* S) {
	return S->top == -1;
}

int isStackFull(StackType* S) {
	return S->top == N - 1;
}

void printStack(StackType* S) {
	if (isStackEmpty(S)) {
		printf("Empty!");
	}
	else {
		for (int i = 0; i <= S->top; i++) {
			printf("%d   ", S->stack[i]);
		}
		printf("\n");
	}
}

void push(StackType* S, int data) {
	if (isStackFull(S)) {
		printf("Full!");
	}
	else {
		S->top++;
		S->stack[S->top] = data;
	}
}

int pop(StackType* S) {
	if (isStackEmpty(S)) {
		printf("Empty!");
		return -1;
	}
	else {
		int e = S->stack[S->top];
		S->top--;
		return e;
	}
}

int stackPeek(StackType* S) {
	return S->stack[S->top];
}

typedef struct QueueType {
	element elem[N];
	int front;
	int rear;
}QueueType;

void initQueue(QueueType* Q) {
	Q->front = Q->rear = 0;
}

int isEmpty(QueueType* Q) {
	return Q->rear == Q->front;
}

int isFull(QueueType* Q) {
	return (Q->rear) + 1 % N == Q->front;
}

void print(QueueType* Q) {
	printf("front pos : %d, rear pos : %d\n", Q->front, Q->rear);

	if (!isEmpty(Q)) {
		int i = Q->front;
		do {
			i = (i + 1) % N;
			printf("[%c] ", Q->elem[i]);
			if (i == Q->rear)
				break;
		} while (i != Q->front);
	}
	printf("\n");
}

void enqueue(QueueType* Q, char e) {
	if (isFull(Q)) {
		printf("FULL");
		return;
	}
	Q->rear = (Q->rear + 1) % N;
	Q->elem[Q->rear] = e;
}

element dequeue(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("EMPTY");
		return 0;
	}
	Q->front = (Q->front + 1) % N;
	return Q->elem[Q->front];
}

element peek(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("EMPTY");
		return 0;
	}
	return Q->elem[Q->front + 1];
}

typedef struct GraphType {
	int n; // ������ ��
	element dajMat[N][N]; // ������� ����
}GraphType;

void initGraph(GraphType* G) {
	G->n = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			G->dajMat[i][j] = 0;
		}
	}
}

void makeVertex(GraphType* G) {
	G->n++;
}

void insertEdge(GraphType* G, element u, element v) {
	if (u > G->n || v > G->n) {
		printf("ERROR!\n");
	}
	else {
		G->dajMat[u][v] = G->dajMat[v][u] = 1;
	}
}

void rDFS(GraphType* G, element s) { // ���� �켱 Ž��
	visited[s] = TRUE; // s�� ���� ����
	printf("[%d] ", s);
	for (int t = 1; t <= G->n; t++) {
		if (G->dajMat[s][t] == 1 && visited[t] == FALSE) { // s,t�� �մ� ������ �ְ�, t�� �湮���� �ʾ��� �� ���ȣ��
			rDFS(G, t);
		}
	}
}

void BFS(GraphType* G, int s) { // �ʺ� �켱 Ž��: ���� �������� ����� �������� ���� �湮�ϴ� ���
	QueueType Q;
	initQueue(&Q);

	visited[s] = TRUE;
	printf("[%d] ", s);
	enqueue(&Q, s);

	while (!isEmpty(&Q)) {
		s = dequeue(&Q); // ť���� �ϳ� ������
		for (int t = 1; t <= G->n; t++) { // ���� �������� �� �� �ִ� �� Ž��
			if (G->dajMat[s][t] == 1 && visited[t] == FALSE) { // ���� �ִ��� Ȯ��
				visited[t] = TRUE; // ���� ����ְ�
				printf("[%d] ", t); // t ȭ�鿡 ���
				enqueue(&Q, t); // t �־��ֱ�
			}
		}
	} // ť�� �� ������ �ݺ�
}

void DFS_iterative(GraphType* G, element s) {
	StackType S;
	initStack(&S);

	push(&S, s);
	int flag;

	while (!isStackEmpty(&S)) {
		s = stackPeek(&S); // ���� �����
		if (visited[s] == FALSE) {
			visited[s] = TRUE;
			printf("[%d]  ", s);
		}
		flag = TRUE;
		for (int t = 1; t <= G->n; t++) {
			if (G->dajMat[s][t]==1 && visited[t] == FALSE) {
				push(&S, t);
				flag = FALSE; // �ݺ����� ������ ����� ����
				break; // �� �� �ִ� ���� ������ �ϴ� �� �־�
			}
		}
		if (flag == TRUE) { // �ݺ����� ������ �� �����̸�
			pop(&S);
		}
	}
}

void printGraph(GraphType* G) {
	for (int i = 1; i <= G->n; i++) {
		printf("|");
		for (int j = 1; j <= G->n; j++) {
			printf(" %d ", G->dajMat[i][j]);
		}
		printf("|\n");
	}
}

int main() {
	GraphType G;
	initGraph(&G);

	int n;
	scanf("%d", &n);
	printf("\n");

	for (int i = 1; i <= n; i++) {
		makeVertex(&G);
	}

	insertEdge(&G, 1, 2); insertEdge(&G, 1, 3); insertEdge(&G, 1, 5);
	insertEdge(&G, 2, 3);
	insertEdge(&G, 3, 4); insertEdge(&G, 3, 5);
	insertEdge(&G, 4, 5);

	printGraph(&G); printf("\n");

	// rDFS(&G, 4); 
	// BFS(&G, 4);
	// DFS_iterative(&G, 4);
}

*/

#define N 10
#define TRUE 1
#define FALSE 0

typedef char element;
element visited[N] = { 0 };
typedef struct StackType {
	int stack[N];
	int top;
}StackType;
void initStack(StackType* S) {
	S->top = -1;
}
int isStackEmpty(StackType* S) {
	return S->top == -1;
}
int isStackFull(StackType* S) {
	return S->top == N - 1;
}
void printStack(StackType* S) {
	if (isStackEmpty(S)) {
		printf("Empty!");
	}
	else {
		for (int i = 0; i <= S->top; i++) {
			printf("%d   ", S->stack[i]);
		}
		printf("\n");
	}
}
void push(StackType* S, int data) {
	if (isStackFull(S)) {
		printf("Full!");
	}
	else {
		S->top++;
		S->stack[S->top] = data;
	}
}
int pop(StackType* S) {
	if (isStackEmpty(S)) {
		printf("Empty!");
		return -1;
	}
	else {
		int e = S->stack[S->top];
		S->top--;
		return e;
	}
}
int stackPeek(StackType* S) {
	return S->stack[S->top];
}
typedef struct QueueType {
	element elem[N];
	int front;
	int rear;
}QueueType;
void initQueue(QueueType* Q) {
	Q->front = Q->rear = 0;
}
int isEmpty(QueueType* Q) {
	return Q->rear == Q->front;
}
int isFull(QueueType* Q) {
	return (Q->rear) + 1 % N == Q->front;
}
void print(QueueType* Q) {
	printf("front pos : %d, rear pos : %d\n", Q->front, Q->rear);

	if (!isEmpty(Q)) {
		int i = Q->front;
		do {
			i = (i + 1) % N;
			printf("[%c] ", Q->elem[i]);
			if (i == Q->rear)
				break;
		} while (i != Q->front);
	}
	printf("\n");
}
void enqueue(QueueType* Q, char e) {
	if (isFull(Q)) {
		printf("FULL");
		return;
	}
	Q->rear = (Q->rear + 1) % N;
	Q->elem[Q->rear] = e;
}
element dequeue(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("EMPTY");
		return 0;
	}
	Q->front = (Q->front + 1) % N;
	return Q->elem[Q->front];
}
element peek(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("EMPTY");
		return 0;
	}
	return Q->elem[Q->front + 1];
}

typedef struct Vertax {
	element vName;
	int isVisit;
	struct AdjacentVertax* aHead;
	struct Vertax* next;
}Vertax;

typedef struct AdjacentVertax {
	element aName;
	struct AdjacentVertax* aHead;
	struct AdjacentVertax* next;
}AdjacentVertax;

typedef struct {
	Vertax* vHead;
}GraphType;

void initGraph(GraphType* G) {
	G->vHead = NULL;
}

void makeVertax(GraphType* G, element vName) {
	Vertax* v = (Vertax*)malloc(sizeof(Vertax));
	v->vName = vName;
	v->isVisit = FALSE;
	v->aHead = NULL;
	v->next = NULL;

	Vertax* p = G->vHead;

	if (p == NULL) { // �׷����� ������ ����
		G->vHead = v;
	}
	else { // ��� ���� ������ �� �ڷ� ���� �پ����
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = v;
	}
}

void printGraph(GraphType* G) {
	Vertax* p = NULL;
	AdjacentVertax* q = NULL;

	for(p = G->vHead; p != NULL; p = p->next) {
		printf("[%c]  ", p->vName);
		for (q = p->aHead; q != NULL; q = q->next) {
			printf("[%c]   ", q->aName);
		}
		printf("\n");
	}
}

Vertax* findVertax(GraphType* G, element vName) {
	Vertax* p = G->vHead;

	while (p->vName != vName) {
		p = p->next;
	}
	return p;
}

void makeAdjacentVertax(Vertax* v, element aName) {
	AdjacentVertax* a = (AdjacentVertax*)malloc(sizeof(AdjacentVertax));
	a->aName = aName;
	a->next = NULL;

	AdjacentVertax* p = v->aHead;

	if (p == NULL) {
		v->aHead = a;
	}
	else {
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = a;
	}

}

void insertEdge(GraphType* G, element v1, element v2) {
	Vertax* v = findVertax(G, v1);
	makeAdjacentVertax(v, v2); // ������ ã�� ������ v2�� ������ ���� ����� �۴�⸦ �׾��ִ� ���(�Լ� qudtls��)

    v = findVertax(G, v2);
	makeAdjacentVertax(v, v1); // �ֹ� ����� �۴�⸦ �׾��ִ� �Լ�

}

void rDFS(GraphType* G, element vName) {
	Vertax* v = findVertax(G, vName);
	AdjacentVertax* a = NULL;

	if (v->isVisit == FALSE) {
		v->isVisit = TRUE;
		printf("[%c]   ", v->vName);
	}
	for (a = v->aHead; a != NULL; a = a->next) {
		v = findVertax(G, a->aName);
		if (v->isVisit == FALSE) {
			rDFS(G, v->vName);
		}
	}
}

void BFS_mine(GraphType* G, element vName) {
	QueueType Q;
	initQueue(&Q);
	Vertax* v;
	AdjacentVertax* a=NULL;

	enqueue(&Q, vName);

	while (!isEmpty(&Q)) {
		vName = dequeue(&Q);
		v = findVertax(G, vName);

		if (v->isVisit == FALSE) {
			v->isVisit = TRUE;
			printf("[%c]   ", v->vName);

			for (a = v->aHead; a != NULL; a = a->next) {
				v = findVertax(G, a->aName);
				if (v->isVisit == FALSE) {
					enqueue(&Q, a->aName);
				}
			}
		}
	}
}

void BFS(GraphType* G, element vName) {
	QueueType Q;
	initQueue(&Q);

	AdjacentVertax* a;

	Vertax* v = findVertax(G, vName);
	v->isVisit = TRUE;
	printf("[%c]   ", v->vName);
	enqueue(&Q, v->vName);

	while (!isEmpty(&Q)) {
		v = findVertax(G, dequeue(&Q));
		for (a = v->aHead; a != NULL; a = a->next) {
			v = findVertax(G, a->aName);
			if (v->isVisit == FALSE) {
				v->isVisit = TRUE;
				printf("[%c]   ", v->vName);
				enqueue(&Q, vName);
			}
		}
	}
}

void DFS_iterative(GraphType* G, element vName) {
	StackType S;
	initStack(&S);
	Vertax* v = NULL;
	AdjacentVertax* a = NULL;

	push(&S, vName);
	int flag;

	while (!isStackEmpty(&S)) {
		vName = stackPeek(&S);
		v = findVertax(G, vName);

		if (v->isVisit == FALSE) {
			v->isVisit = TRUE;
			printf("[%c]   ", v->vName);
		}

		flag = TRUE;

		for (a = v->aHead; a != NULL; a = a->next) {
			v = findVertax(G, a->aName);

			if (v->isVisit == FALSE) {
				v->isVisit = TRUE;
				printf("[%c]   ", v->vName);
				push(&S, v->vName);
				flag = FALSE;
				break;
			}
		}

		if (flag == TRUE) {
			pop(&S);
		}
	}
}


int main() {
	GraphType G;
	initGraph(&G);

	makeVertax(&G,'a'); makeVertax(&G, 'b'); makeVertax(&G, 'c'); makeVertax(&G, 'd'); makeVertax(&G, 'e'); makeVertax(&G, 'f'); makeVertax(&G, 'g');

	insertEdge(&G, 'a', 'b'); insertEdge(&G, 'a', 'f'); 
	insertEdge(&G, 'b', 'c'); insertEdge(&G, 'b', 'g'); 
	insertEdge(&G, 'c', 'd');
	insertEdge(&G, 'd', 'e'); insertEdge(&G, 'd', 'g');
	insertEdge(&G, 'e', 'f'); insertEdge(&G, 'e', 'g');
	printGraph(&G);

	// printf("rDFS: "); rDFS(&G, 'g'); printf("\n");
	printf("DFS_iterative: "); DFS_iterative(&G, 'g');
}

