#include<stdio.h>
#include<stdlib.h>
#define N 50

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
	if (isStackEmpty(&S)) {
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

int peek(StackType* S) {
	return S->stack[S->top];
}

int main() {
	StackType S;
	initStack(&S);

	push(&S, 1); printStack(&S);
	push(&S, 2); printStack(&S);
	push(&S, 3); printStack(&S);
	push(&S, 4); printStack(&S);

	pop(&S); printStack(&S);
	printf("%d", peek(&S));
}
