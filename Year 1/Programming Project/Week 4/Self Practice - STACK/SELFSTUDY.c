#include<stdio.h>
#include<stdlib.h>
#define N 50

typedef struct StackType {
	int top;
	int stack[N];
}StackType;

void initStack(StackType* S) {
	S->top = -1;
}

void printStack(StackType* S) {
	if (isEmpty(S)) {
		printf("Empty!");
	}
	else {
		for (int i = 0; i <= S->top; i++) {
			printf("%d  ", S->stack[i]);
		}
	}
	printf("\n");
}

int isEmpty(StackType* S) {
	return S->top == -1;
}

int isFull(StackType* S) {
	return S->top == N - 1;
}

void push(StackType* S, int i) {
	if (isFull(S)) {
		printf("OverFlow!");
	}
	else {
		S->top++;
		S->stack[S->top] = i;
	}
}

int pop(StackType* S) {
	if (isEmpty(S)) {
		printf("Empty!");
		return -1;
	}
	else {
		int i = S->stack[S->top];
		S->top--;
		return i;
	}
}

int main() {
	StackType S;
	initStack(&S);
	push(&S, 1);
	push(&S, 2);
	push(&S, 3);
	push(&S, 4);
	push(&S, 5);
	printStack(&S);

	pop(&S);
	printStack(&S);
	pop(&S);
	printStack(&S);
	pop(&S);
	printStack(&S);
	pop(&S);
	printStack(&S);
	pop(&S);
	printStack(&S);
	pop(&S);
	printStack(&S);
}


