#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

// ��

/*
#define N 100

typedef int element;

typedef struct HeapType {
	element heap[N];
	int heapSize;
}HeapType;

void initHeap(HeapType* H) {
	H->heapSize = 0;
}

void upHeap(HeapType* H) { // ��� ����
	int i = H->heapSize;
	element key = H->heap[i];

	while ((i != 1) && (key > H->heap[i / 2])) { // �θ������ �ö󰡰ų�(i=1) Ű���� �θ����� �ͺ��� ���� ������ �ݺ�
		H->heap[i] = H->heap[i / 2]; // �θ� ����� ���� �ڽ� ����� ���� ����
		i = i / 2; 
		H->heap[i] = key; // Ű�� �θ������� �־���
	}
	H->heap[i] = key; 
}

void downHeap(HeapType* H) { // ���� ū ���� ������ �ִ� ��Ʈ ��带 �����ϰ� ���� �ٽ� �����ϴ� �Լ�
	element item = H->heap[1]; // ������=��Ʈ ����� ��
	int parent = 1, child = 2; 

	while (child <= H->heapSize) { // �ڽĳ�尡 �����ϴ� ����
		if ((child < H->heapSize) && (H->heap[child + 1]) > H->heap[child]) { ���ϵ尡 ������� �۰� ������ ����� ���� �� ũ�ٸ�
			child++; // ������ ���� �ڽ� ��带 ����
		}
		if (item >= H->heap[child]) {
			break; // ���� �˻����� item�� ���� �ڽĺ��� ũ��->�� �Ӽ� �����ؼ� ����
		}
		H->heap[parent] = H->heap[child]; // �θ� ��忡 �ڽ� ����� �� ����
		parent = child; // �θ� �ڽ� �ε��� ��ȯ
		child *= 2; // ���� �ڽ� ���� �̵�
	}
	H->heap[parent] = item; 
}

void insertItem(HeapType* H, element key) {
	H->heapSize++;
	H->heap[H->heapSize] = key;
	upHeap(H);
}

element removeItem(HeapType* H) {
	element item = H->heap[1];

	H->heap[1] = H->heap[H->heapSize];
	H->heapSize--;
	downHeap(H);

	return item;
}

void heapSort(HeapType* H) {
	int n = H->heapSize;
	element A[n];
	for (int i = n - 1; i >= 0; i--) {
		A[i] = removeItem(H);
	}
	for (int i = 0; i < n; i++) {
		printf("[%d]   ", A[i]);
	}
	printf("\n");
}

void printHeap(HeapType* H) {
	for (int i = 1; i <= H->heapSize; i++) {
		printf("[%d]  ", H->heap[i]);
	}
	printf("\n");
}


int main() {
	HeapType H;
	initHeap(&H);

	insertItem(&H, 9); insertItem(&H, 7); insertItem(&H, 6);
	insertItem(&H, 5); insertItem(&H, 4); insertItem(&H, 3);
	insertItem(&H, 2); insertItem(&H, 2); insertItem(&H, 1);
	insertItem(&H, 3); printHeap(&H); getchar();

	// insertItem(&H, 8); printHeap(&H);

	removeItem(&H); printHeap(&H);
}
*/

/* ��ķ� ��Ÿ�� �׷��� */

#define N 10
#define TRUE 1
#define FALSE 0

typedef int element;
element visited[N] = { 0 };

typedef struct QueueType {
	element elem[N];
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

void print(QueueType* Q) {
	printf("front pos : %d, rear pos : %d\n", Q->front, Q->rear);

	if (!isQueueEmpty(Q)) {
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

element peek(QueueType* Q) {
	if (isQueueEmpty(Q)) {
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

void rDFS(GraphType* G, element s) {
	visited[s] = TRUE;
	printf("[%d] ", s);
	for (int t = 1; t <= G->n; t++) {
		if (G->dajMat[s][t] == 1 && visited[t] == FALSE) {
			rDFS(G, t);
		}
	}
}

void BFS(GraphType* G, int s) {
	QueueType Q;
	initQueue(&Q);

	visited[s] = TRUE;
	printf("[%d] ", s);
	enqueue(&Q, s);

	while (!isQueueEmpty(&Q)) {
		s = dequeue(&Q);
		for (int t = 1; t <= G->n; t++) {
			if (G->dajMat[s][t] == 1 && visited[t] == FALSE) {
				visited[t] = TRUE;
				printf("[%d] ", t);
				enqueue(&Q, t);
			}
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
	BFS(&G, 4);
}
