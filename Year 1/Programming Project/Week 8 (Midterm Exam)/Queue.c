#include<stdio.h>
#include<stdlib.h>
#define N 50

typedef int element;

typedef struct QueueType {
	int front;
	int rear;
	element Queue[N];
}QueueType;

void initQueue(QueueType* Q) {
	Q->front = -1;
	Q->rear = -1;
}

int isEmpty(QueueType* Q) {
	return  Q->rear == -1;
}

int isFull(QueueType* Q) {
	return Q->front == N - 1;
}

void printQueue(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("EMPTY!");
	}
	printf("front : %d, rear : %d\n", Q->front, Q->rear);
	for (int i = 0; i <= Q->rear; i++) {
		printf("%d   ", Q->Queue[i]);
	}
	printf("\n");
}

void enqueue(QueueType* Q, element e) {
	if (isFull(Q)) {
		printf("FULL!");
	}
	Q->rear++;
	Q->Queue[Q->rear] = e;
}

element dequeue(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("EMPTY!");
	}
	element e = Q->Queue[Q->front + 1];
	Q->front++;
	return e;
}

int main() {
	QueueType Q;
	initQueue(&Q);

	enqueue(&Q, 1); printQueue(&Q);
	enqueue(&Q, 2); printQueue(&Q);
	enqueue(&Q, 3); printQueue(&Q);
	enqueue(&Q, 4); printQueue(&Q);
	enqueue(&Q, 5); printQueue(&Q);
	enqueue(&Q, 6); printQueue(&Q);

}
