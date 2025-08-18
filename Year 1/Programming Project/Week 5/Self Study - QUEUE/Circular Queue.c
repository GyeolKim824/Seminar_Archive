#include<stdio.h>
#include<stdlib.h>
#define N 8

typedef char element;

typedef struct circleQueueType {
	int front;
	int rear;
	element elem[N];
}circleQueueType;

void init_circleQueue(circleQueueType* Q) {
	Q->front = Q->rear = 0;
}

int is_circleQueue_Empty(circleQueueType* Q) {
	return Q->front == Q->rear;
}

int is_circleQueue_Full(circleQueueType* Q) {
	return Q->front == (Q->rear + 1) % N;
}

void printQueue(circleQueueType* Q) {
	printf("front pos: %d, rear pos: %d\n", Q->front, Q->rear);
	
	if (!is_circleQueue_Empty(Q)) {
		int i = Q->front;
		while (i != Q->rear) {
			i = (i + 1) % N;
			printf("[%c]", Q->elem[i]);
		}
		printf("\n\n");
	}
}

void enQueue(circleQueueType* Q, element e) {
	if (is_circleQueue_Full(Q)) {
		printf("FULL!");
	}
	else {
		Q->rear = (Q->rear + 1) % N;
		Q->elem[Q->rear] = e;
	}
}

element deQueue(circleQueueType* Q) {
	if (is_circleQueue_Empty(Q)) {
		printf("EMPTY!");
		return 0;
	}
	else {
		element tmp = Q->elem[Q->front + 1];
		Q->front = (Q->front + 1) % N;
		return tmp;
	}
}

int main() {
	circleQueueType Q;
	init_circleQueue(&Q);

	enQueue(&Q, 'K');
	enQueue(&Q, 'I');
	enQueue(&Q, 'M');
	enQueue(&Q, 'G');
	enQueue(&Q, 'Y');
	enQueue(&Q, 'E');
	enQueue(&Q, 'O');
	printQueue(&Q);

	deQueue(&Q);
	printQueue(&Q);

	enQueue(&Q, 'L');
	printQueue(&Q);

	enQueue(&Q, 'K');
	deQueue(&Q);
	printQueue(&Q);

	enQueue(&Q, 'K');
	printQueue(&Q);

}