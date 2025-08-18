#include<stdio.h>
#include<stdlib.h>
#define N 50

typedef char element;
typedef struct QueueType {
	element elem[N];
	int front;
	int rear;
}QueueType;

void initQueue(QueueType* Q) {
	Q->front = Q->rear = -1;
}

int isQueueEmpty(QueueType* Q) {
	return Q->front == Q->rear;
}

int isQueueFull(QueueType* Q) {
	return Q->rear == N - 1;
}

void printQueue(QueueType* Q) {
	if (isQueueEmpty(Q)) {
		printf("Empty!");
	}
	else {
		for (int i = Q->front + 1; i <= Q->rear; i++) {
			printf("%c  ", Q->elem[i]);
		}
	}
	printf("\n");
}

void enqueue(QueueType* Q, element e) {
	if (isQueueFull(Q)) {
		printf("Full!");
	}
	else {
		Q->rear++;
		Q->elem[Q->rear] = e;
	}
}

element dequeue(QueueType* Q) {
	if (isQueueEmpty(Q)) {
		printf("Empty!");
	}
	else {
		element tmp = Q->elem[Q->front + 1];
		Q->front++;
		return tmp;
	}
}

int main() {
	QueueType Q;
	initQueue(&Q);
	enqueue(&Q, 'K');
	enqueue(&Q, 'I');
	enqueue(&Q, 'M');
	printQueue(&Q);

	dequeue(&Q);
	printQueue(&Q);
	dequeue(&Q);
	printQueue(&Q);
	dequeue(&Q);
	printQueue(&Q);


}
