#include<stdio.h>
#include<stdlib.h>
#define N 8

typedef int element;

typedef struct DequeType {
	int front;
	int rear;
	element Deque[N];
}DequeType;

void initDeque(DequeType* D) {
	D->front = D->rear = 0;
}

int isDequeEmpty(DequeType* D) {
	return D->front == D->rear;
}

int isDequeFull(DequeType* D) {
	return D->front == (D->rear + 1) % N;
}

void printDeque(DequeType* D) {
	if (isDequeEmpty(D)) {
		printf("EMPTY!!");
	}
	else {
		printf("front : %d, rear : %d\n", D->front, D->rear);
		int i = D->front;
		do {
			i = (i + 1) % N;
			printf("[%d] ", D->Deque[i]);
			if (i == D->rear) {
				break;
			}
		} while (i != D->front);
		printf("\n");
	}
}

void addFront(DequeType*D, element e){
	if (isDequeFull(D)) {
		printf("FULL");
		return;
	}
	else {
		D->front = (D->front - 1 + N) % N;
		D->Deque[D->front] = e;
	}
}

void addRear(DequeType* D, element e) {
	if (isDequeFull(D)) {
		printf("FULL");
		return;
	}
	else {
		D->rear = (D->rear + 1) % N;
		D->Deque[D->rear] = e;
	}
}

element deleteFront(DequeType* D) {
	if (isDequeEmpty(D)) {
		printf("EMPTY!!");
		return -1;
	}
	else {
		D->front = (D->front + 1) % N;
		return D->Deque[D->front];
	}
}

element deleteRear(DequeType* D) {
	if (isDequeEmpty(D)) {
		printf("EMPTY!!");
		return -1;
	}
	else {
		element e = D->Deque[D->rear];
		D->rear = (D->rear-1+N) % N;
		return e;
	}
}

element getFront(DequeType* D) {
	if (isDequeEmpty(D)) {
		printf("EMPTY!!");
		return -1;
	}
	else {
		return D->Deque[(D->front + 1) % N];
	}
}

element getRear(DequeType* D) {
	if (isDequeEmpty(D)) {
		printf("EMPTY!!");
		return -1;
	}
	else {
		return D->Deque[D->rear];
	}
}

int main() {
	DequeType D;
	initDeque(&D);

	addFront(&D, 1);
	addFront(&D, 9);
	printDeque(&D);

	addRear(&D, 2);
	printDeque(&D);

}
