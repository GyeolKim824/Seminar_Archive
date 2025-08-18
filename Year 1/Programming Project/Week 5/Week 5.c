#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100
#define SIZE_1 10
/* 선형 큐 구현
typedef char element;
typedef struct QueueType {
	element elem[SIZE];
	int front;
	int rear;
}QueueType;

void initQueue(QueueType* Q) {
	Q->front = Q->rear = -1;
}

int isEmpty(QueueType* Q) {
	return Q->front == Q->rear;
}

int isFull(QueueType* Q) {
	return Q->rear == SIZE - 1;
}

void print(QueueType* Q) {
	printf("front pos : %d, rear pos : %d\n", Q->front, Q->rear);

	if (!isEmpty(Q)) {
		for (int i = Q->front + 1; i <= Q->rear; i++) {
			printf("[%c] ", Q->elem[i]);
		}
		printf("\n");
	}
}


void enqueue(QueueType* Q, char e) {
	if (isFull(Q)) {
		printf("FULL");
		return;
	}
	Q->rear++;
	Q->elem[Q->rear] = e;
}

element dequeue(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("EMPTY");
		return 0;
	}
	Q->front++;
	return Q->elem[Q->front];
}

element peek(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("EMPTY");
		return 0;
	}
	return Q->elem[Q->front+1];
}

int main() {
	QueueType Q;
	initQueue(&Q);
	srand(time(NULL));

	for (int i = 0; i < 7; i++) {
		enqueue(&Q, rand() % 26 + 65);
	}
	print(&Q);

	for (int i = 0; i < 3; i++) {
		printf("[%c] ", dequeue(&Q));
	}
	printf("\n\n");
	print(&Q);

	printf("[%c]\n\n", peek(&Q));
	print(&Q);

	printf("\n");
	for (int i = 0; i < 5; i++) {
		enqueue(&Q, rand() % 26 + 65);
	}
	print(&Q);

	for (int i = 0; i < 3; i++) {
		printf("[%c] ", dequeue(&Q));
	}
	printf("\n\n");
	print(&Q);
}
*/

/* 원형 큐 구현
typedef char element;
typedef struct QueueType {
	element elem[SIZE_1];
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
	return (Q->rear) + 1 % SIZE_1 == Q->front;
}

void print(QueueType* Q) {
	printf("front pos : %d, rear pos : %d\n", Q->front, Q->rear);

	if (!isEmpty(Q)) {
		int i = Q->front;
		do {
			i = (i + 1) % SIZE_1;
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
	Q->rear=(Q->rear+1)%SIZE_1;
	Q->elem[Q->rear] = e;
}

element dequeue(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("EMPTY");
		return 0;
	}
	Q->front = (Q->front + 1) % SIZE_1;
	return Q->elem[Q->front];
}

element peek(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("EMPTY");
		return 0;
	}
	return Q->elem[Q->front + 1];
}

int main() {
	QueueType Q;
	initQueue(&Q);
	srand(time(NULL));

	for (int i = 0; i < 7; i++) {
		enqueue(&Q, rand() % 26 + 65);
	}
	print(&Q);

	for (int i = 0; i < 3; i++) {
		printf("[%c] ", dequeue(&Q));
	}
	printf("\n\n");
	print(&Q);

	printf("[%c]\n\n", peek(&Q));
	print(&Q);

	printf("\n");
	for (int i = 0; i < 5; i++) {
		enqueue(&Q, rand() % 26 + 65);
	}
	print(&Q);

	for (int i = 0; i < 3; i++) {
		printf("[%c] ", dequeue(&Q));
	}
	printf("\n\n");
	print(&Q);
}
*/

/*덱 구현(front와 rear에서 모두 삽입과 삭제가 가능한 큐)
typedef char element;
typedef struct DequeType {
	element elem[SIZE_1];
	int front;
	int rear;
}DequeType;

void initDeque(DequeType* D) {
	D->front = D->rear = 0;
}

int isEmpty(DequeType* D) {
	return D->front == D->rear;
}

int isFull(DequeType* D) {
	return (D->rear + 1) % SIZE_1 == D->front;
}

void print(DequeType* D) {
	printf("front pos : %d, rear pos : %d\n", D->front, D->rear);

	if (!isEmpty(D)) {
		int i = D->front;
		do {
			i = (i + 1) % SIZE_1;
			printf("[%c] ", D->elem[i]);
			if (i == D->rear)
				break;
		} while (i != D->front);
	}
	printf("\n");
}

void addRear(DequeType* D, char e) {
	if (isFull(D)) {
		printf("FULL");
		return;
	}
	D->rear = (D->rear + 1) % SIZE_1;
	D->elem[D->rear] = e;
}

element deleteFront(DequeType* D) {
	if (isEmpty(D)) {
		printf("EMPTY");
		return 0;
	}
	D->front=(D->front+1)%SIZE_1;
	return D->elem[D->front];
}

element getFront(DequeType* D) {
	if (isEmpty(D)) {
		printf("EMPTY");
		return 0;
	}
	return D->elem[(D->front + 1)%SIZE_1];
}
 
void addFront(DequeType* D, char e) {
	if (isFull(D)) {
		printf("FULL\n");
		return;
	}
	D->elem[D->front] = e;
	D->front = (D->front - 1 + SIZE_1) % SIZE_1;
}

element deleteRear(DequeType* D) {
	if (isEmpty(D)) {
		printf("Empty");
		return 0;
	}
	int pos = D->rear;
	D->rear = (D->rear - 1 + SIZE_1) % SIZE_1;
	return D->elem[pos];
}

element geteRear(DequeType* D) {
	if (isEmpty(D)) {
		printf("Empty");
		return 0;
	}
	return D->elem[D->rear];
}

int main() {
	DequeType D;
	initDeque(&D);
	srand(time(NULL));

	for (int i = 0; i < 7; i++) {
		addRear(&D, rand() % 26 + 65);
	}
	print(&D);

	for (int i = 0; i < 3; i++) {
		printf("[%c] ", deleteFront(&D));
	}
	printf("\n\n");
	print(&D);

	printf("\n");
	for (int i = 0; i < 5; i++) {
		addFront(&D, rand() % 26 + 65);
	}
	print(&D);

	for (int i = 0; i < 3; i++) {
		printf("[%c] ", deleteRear(&D));
	}
	printf("\n\n");
	print(&D);
}
*/

#define N 10
#define M 100

typedef int element;
typedef struct StackType {
	int top;
	int stack[N];
}StackType;

void initStack(StackType* S) { // stack 초기화
	S->top = -1;
}

int isStackFull(StackType* S) {
	return S->top == N - 1;
}

int isStackEmpty(StackType* S) {
	return S->top == -1;
}

void push(StackType* S, element e) {
	if (isStackFull(S)) {
		printf("Overflow!\n");
	}
	else {
		S->top++;
		S->stack[S->top] = e;
	}
}

element pop(StackType* S) {
	if (isStackEmpty(S)) {
		printf("Empty!\n");
		return -1;
	}

	element e = S->stack[S->top];
	S->top--;
	return e;
}

element top(StackType* S) {
	if (isStackEmpty(S)) {
		printf("Empty!\n");
		return -1;
	}

	return S->stack[S->top];
}

void sortedPush(StackType* S, element e) {
	int tmp;
	if (isStackEmpty(S)||e>top(S)) {
		push(S, e);
	}
	else {
		tmp = pop(S);
		sortedPush(S, e);
		push(S, tmp);
	}

}

void printStack(StackType* S) {
	for (int i = 0; i <= S->top; i++) {
		printf("%d  ", S->stack[i]);
	}
	printf("\n");
}
typedef int element;

typedef struct QueueType {
	int elem[N];
	int front;
	int rear;
}QueueType;

void initQueue(QueueType* Q) {
	Q->front = Q->rear = 0;
}

int isQueueEmpty(QueueType* Q) {
	return Q->rear == Q->front;
}

int isQueueFull(QueueType* Q) {
	return (Q->rear) + 1 % N == Q->front;
}

void printQueue(QueueType* Q) {
	int i = Q->front;
	while (i != Q->rear) {
		i = (i + 1) % N;
		printf("[%d] ", Q->elem[i]);
	}
	printf("\n");
}

void enqueue(QueueType* Q, element e) {
	if (isQueueFull(Q)) {
		printf("FULL");
		return;
	}
	Q->rear = (Q->rear + 1) % N;
	Q->elem[Q->rear] = e;
}

element dequeue(QueueType* Q) {
	if (isQueueEmpty(Q)) {
		printf("EMPTY");
		return 0;
	}
	Q->front = (Q->front + 1) % N;
	return Q->elem[Q->front];
}

element front(QueueType* Q) {
	if (isQueueEmpty(Q)) {
		printf("EMPTY");
		return 0;
	}
	return Q->elem[Q->front + 1];
}

void reverseElementStack(StackType* S, int k) {
	QueueType Q;
	initQueue(&Q);
	int i = 0;

	while (!isStackEmpty(S)&&i<k) {
		enqueue(&Q, pop(S));
		i++;
	}
	while (!isQueueEmpty(&Q)) {
		push(S, dequeue(&Q));
	}
}

void reverseElementQueue(QueueType* Q, int k) {
	StackType S;
	initStack(&S);
	int i = 0;

	while (!isQueueEmpty(Q) && i < k) {
		push(&S, dequeue(Q));
		i++;
	}
	while (!isStackEmpty(&S)) {
		enqueue(Q, pop(&S));
	}

	int diff = queueSize(Q) - k;

	while (diff > 0) {
		int tmp = dequeue(Q);
		enqueue(Q, tmp);
		diff--;
	}
}

int queueSize(QueueType* Q) {
	return (N - Q->front + Q->rear) % N;
}


/* 예제 1 
int main() {
	StackType S;
	initStack(&S);

	element data[6] = { 5,3,8,1,2,7 };

	for (int i = 0; i < 6; i++) {
		sortedPush(&S, data[i]);
		printStack(&S);
	}
}
*/

/*예제 2 -> 스택에서 큐로, 큐에서 스택으로
int main() {
	StackType S;
	initStack(&S);

	element data[6] = { 5,3,8,1,2,7 };

	for (int i = 0; i < 6; i++) {
		push(&S, data[i]);
		printStack(&S);
	}

	reverseElementStack(&S, 4);
	printStack(&S);
}
*/

/*예제 2 -> 큐에서 스택으로, 스택에서 큐로*/
int main() {
	QueueType Q;
	initQueue(&Q);

	element data[6] = { 5,3,8,1,2,7 };

	for (int i = 0; i < 6; i++) {
		enqueue(&Q, data[i]);
	}
	printQueue(&Q);

	reverseElementQueue(&Q, 4);
	printQueue(&Q);
}
