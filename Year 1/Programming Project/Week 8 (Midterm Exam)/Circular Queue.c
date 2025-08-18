#include<stdio.h>
#include<stdlib.h>
#define N 10

typedef int element;

typedef struct QueueType {
	int front;
	element Queue[N];
	int rear;
}QueueType;

void initQueue(QueueType* Q) {
	Q->front = Q->rear = 0;
}

int isEmpty(QueueType* Q) {
	return Q->front == Q->rear;
}

int isFull(QueueType* Q) {
	return (Q->rear + 1) % N == Q->front;
}

void printQueue(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("EMPTY!!");
	}
	else {
		printf("front : %d, rear : %d\n", Q->front, Q->rear);
		int i = Q->front;
		do {
			i = (i + 1) % N;
			printf("[%d]  ", Q->Queue[i]);
			if (i == Q->rear) {
				break;
			}

		} while (i != Q->front);
	}
	printf("\n");	
}

void enqueue(QueueType* Q, element e) {
	if (isFull(Q)) {
		printf("FULL!!");
	}
	else {
		Q->rear = (Q->rear + 1) % N;
		Q->Queue[Q->rear] = e;
	}
}

element dequeue(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("EMPTY!!");
	}
	else {
		element e = Q->Queue[Q->front];
		Q->front = (Q->front + 1) % N;
		return e;
	}
}

element peek(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("EMPTY!!");
	}
	else {
		return Q->Queue[++Q->front];
	}
}

int main() {
	QueueType Q;
	initQueue(&Q);
	enqueue(&Q, 1); 
	enqueue(&Q, 2);
	enqueue(&Q, 3);
	enqueue(&Q, 4);
	enqueue(&Q, 5);
	enqueue(&Q, 6);
	enqueue(&Q, 7);
	enqueue(&Q, 8);
	dequeue(&Q);
	dequeue(&Q);
	enqueue(&Q, 9);
	enqueue(&Q, 10);
	enqueue(&Q, 11); printQueue(&Q);

	printf("%d",peek(&Q));
}
