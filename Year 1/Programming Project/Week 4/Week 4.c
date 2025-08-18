#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 100


typedef struct StackType {
	int top;
	char stack[N];
}StackType;

void init(StackType *S) { // stack �ʱ�ȭ
	S->top = -1;
}

int isFull(StackType *S){
	return S->top == N - 1;
}

int isEmpty(StackType *S) {
	return S->top == -1;
}

void push(StackType* S, char c) {
	if (isFull(S)) {
		printf("Overflow!\n");
	}
	else {
		S->top++;
		S->stack[S->top] = c;
	}
}

char pop(StackType* S) {
	if (isEmpty(S)) {
		printf("Empty!\n");
		return -1;
	}
	
	char c = S->stack[S->top];
	S->top--;
	return c;
}

char peek(StackType* S) {
	if (isEmpty(S)) {
		printf("Empty!\n");
		return -1;
	}

	return S->stack[S->top];
}

void print(StackType* S) {
	for (int i = 0; i <= S->top; i++) {
		printf("%c  ", S->stack[i]);
	}
	printf("\n");
}

/*
int main() {
	StackType S;
	init(&S);
	push(&S, 'C');
	push(&S, 'a');
	push(&S, 't');
	push(&S, 's');
	print(&S);
	
	printf("%c is popped\n", pop(&S));
	print(&S);

	printf("%c is peeked\n", peek(&S));
	print(&S);
}   
*/

/* ��ȣüũ ���� 
int check(char expr[]) {
	StackType S;
	init(&S);

	char c, t;
	int n = strlen(expr);

	for (int i = 0; i < n; i++) {
		c = expr[i];

		if (c == '(' ||c=='{' ||c=='[') {
			push(&S, c);
		}
		else if (c == ')' || c == '}' || c == ']') {
			if (isEmpty(&S)) {
				return 0;
			}
			else {
				t = pop(&S);
				if ((t == '(' && c != ')') || (t == '{' && c != '}') || (t == '[' && c != ']')) {
					return 0;
				}
			}
		}
	}
	return isEmpty(&S);
}

int main() {
	char expr[N];
	scanf("%s", expr);

	if (check(expr)) {
		printf("Success!\n");
	}
	else {
		printf("Fail!\n");
	}
}

*/

/*���� ǥ��� ��� ���� --> �ǿ����ڴ� ���ÿ� �־�ΰ�, �����ڸ� ������ ���ڸ� ���� �� ����� Ǫ��

char evaluate(char postfix[]) {
	StackType S;
	init(&S);

	int op1,op2,value;
	char c;
	int n = strlen(postfix);

	for (int i = 0; i < n; i++) {
		c = postfix[i];

		if (c != '+' && c != '-' && c != '*' && c != '/') { // �о���� ���ڰ� ������ ��(�����ڰ� �ƴ� ��)
			value = c-'0'; //  ���� Ÿ���� ���� c�� ��¥ ���ڷ� �ٲ��ֱ� ���� "value - 0" ���
			push(&S, value);
		}
		else { // �о���� ���ڰ� �������� ��
			op2 = pop(&S);
			op1 = pop(&S);
			switch (c) {
			case '+':
				push(&S, op1 + op2);
				break;
			case'-':
				push(&S, op1 - op2);
				break;
			case'*':
				push(&S, op1 * op2);
				break;
			case'/':
				push(&S, op1 / op2);
				break;
			}
		}
	}
	return pop(&S);
}

int main() {
	char postfix[N];
	scanf("%s", postfix);

	printf("%d\n", evaluate(postfix));
}
*/

/*���� ǥ���->���� ǥ��� ��ȯ ���� --> �ǿ����ڴ� ȭ�鿡 ǥ��, �����ڴ� ���ÿ� ����(push�� �� ������ �켱���� ����ؼ� ����)*/
int prec(char op) {
	switch (op) {
	case'(': case')':
		return 0;
		break;
	case'+': case'-':
		return 1;
		break;
	case'*': case'/':
		return 2;
		break;
	}
}


void convert(char infix[]) {
	StackType S;
	init(&S);

	char c, t;
	int n = strlen(infix);

	for (int i = 0; i < n; i++) {
		c = infix[i];

		switch (c) {
		case '+': case '-': case '*': case '/': 
			while (!isEmpty(&S) && prec(c) <= prec(peek(&S))) {
				printf("%c", pop(&S));
			}
			push(&S, c);
			break;
		case '(':
			push(&S, c);
			break;
		case ')':
			t = pop(&S);
			while (t != '(') {
				printf("%c", t);
				t = pop(&S);
			}
			break;
		default:
			printf("%c", c);
			break;

		}
	}
	while (!isEmpty(&S)) {
		printf("%c", pop(&S));
	}
	printf("\n");
}


int main() {
	char infix[N];
	scanf("%s", infix);

	convert(infix);
}

