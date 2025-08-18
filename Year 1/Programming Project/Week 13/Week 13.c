/*
* 
#include<stdio.h>
#include<stdlib.h>

#define N 10
#define TRUE 1
#define FALSE 0
#define INF 1000

typedef char element;
int dist[N]; // ���ͽ�Ʈ�� ���Ͽ� ������ ���̺�
element visited[N] = { 0 };

typedef struct Edge {
	element v1, v2;
	int weight;
	struct Edge* next;
}Edge;

typedef struct Vertex {
	element vName;
	int isVisit;
	struct AdjacentVertex* aHead;
	struct Vertex* next;
}Vertex;

typedef struct AdjacentVertex {
	element aName;
	Edge* e;
	struct AdjacentVertex* next;
}AdjacentVertex;

typedef struct {
	Vertex* vHead;
	Edge* eHead;
	int vCount, eCount; // ���� ����, ���� ����
}GraphType;

void initGraph(GraphType* G) {
	G->vHead = NULL;
	G->eHead = NULL;
	G->vCount = G->eCount = 0;

	for (int i = 0; i < N; i++) {
		dist[i] = INF;
	}
}

void makeVertax(GraphType* G, element vName) {
	Vertex* v = (Vertex*)malloc(sizeof(Vertex));
	v->vName = vName;
	v->isVisit = FALSE;
	v->aHead = NULL;
	v->next = NULL;

	G->vCount++;

	Vertex* p = G->vHead;

	if (p == NULL) { // �׷����� ������ ����
		G->vHead = v;
	}
	else { // ��� ���� ������ �� �ڷ� ���� �پ����
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = v;
	}
}

void printGraph(GraphType* G) {
	Vertex* v = NULL;
	AdjacentVertex* a = NULL;

	for (v = G->vHead; v != NULL; v = v->next) {
		printf("[%c]  ", v->vName);
		for (a = v->aHead; a != NULL; a = a->next) {
			printf("[%c, %d]   ", a->aName, a->e->weight);
		}
		printf("\n");
	}
}

Vertex* findVertex(GraphType* G, element vName) {
	Vertex* p = G->vHead;

	while (p->vName != vName) {
		p = p->next;
	}
	return p;
}

void makeAdjacentVertex(Vertex* v, element aName, Edge* e) {
	AdjacentVertex* a = (AdjacentVertex*)malloc(sizeof(AdjacentVertex));
	a->aName = aName;
	a->e = e;
	a->next = NULL;

	AdjacentVertex* p = v->aHead;

	if (p == NULL) {
		v->aHead = a;
	}
	else {
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = a;
	}
}

void insertEdge(GraphType* G, element v1, element v2, int weight) {
	Edge* e = (Edge*)malloc(sizeof(Edge));
	e->v1 = v1;
	e->v2 = v2;
	e->weight = weight;
	e->next = NULL;

	G->eCount++;

	Edge* p = G->eHead;

	if (p == NULL) {
		G->eHead = e;
	}
	else {
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = e;
	}
	Vertex* v = findVertex(G, v1);
	makeAdjacentVertex(v, v2, e);

	v = findVertex(G, v2);
	makeAdjacentVertex(v, v1, e);
}

void incSort(GraphType* G, Edge* edges[]) {
	int i, least;
	Edge* p = G->eHead;

	for (i = 0; i < G->eCount; i++) {
		edges[i] = p; // ����ġ �Ű� �Ⱦ��� �ϴ� �迭���ٰ� �־� 
		p = p->next;
	}
	for (i = 0; i < G->eCount - 1; i++) { // �ٱ� ������ ����-1 ��ŭ�� ���� -> �̹� �ּڰ� ���� ����
		least = i; // �ּڰ��� ������ �ε��� ����
		for (int j = i + 1; j < G->eCount; j++) { // i ����ĭ���� ������ ����
			if (edges[j]->weight < edges[least]->weight) {
				least = j;
			}
		}
		p = edges[least];
		edges[least] = edges[i];
		edges[i] = p;
	} // ���� ��!

	for (i = 0; i < G->eCount; i++) {
		printf("[%c%c%d] ", edges[i]->v1, edges[i]->v2, edges[i]->weight);
	}
}

/*
*
int vFind(int vertices[], int vNum) {
	if (vertices[vNum] == -1) {
		return vNum;
	}
	while (vertices[vNum] != -1) {
		vNum=vertices[vNum]; // ���� ���տ� �ִ� �������� ����. ��� b(1)�� -1 c(2)�� 1, g�� 2�ε� ���� g�� �������� g->c->b�� �̵��ؼ� -1�� ã��

		return vNum; // �׶� vNum ������
	}
}

void vUnion(int vertices[], int vNum1, int vNum2) {
	vertices[vNum2] = vNum1;
}

void kruskal(GraphType* G, Edge* edges[], int vertices[]) {
	int eCnt = 0; int i = 0;

	int vNum1, vNum2;
	Edge* p;

	while (eCnt < G->vCount - 1) {
		p = edges[i];
		vNum1 = vFind(vertices, p->v1 - 97); // ĳ���͸� ��Ʈ�� ���ַ��� -97
		vNum2 = vFind(vertices, p->v2 - 97);

		if (vNum1 != vNum2) {
			eCnt++;
			printf("%d. [%c%c %d]\n", eCnt, p->v1, p->v2, p->weight);
			vUnion(vertices, vNum1, vNum2);
		}
		i++;
	}
}

element getMinVertex(GraphType* G, int dist[]) { // �ּ� ��θ� ã�� ��ȯ�ϴ� �Լ�
	Vertex* v = NULL;
	element name;

	for (v = G->vHead; v != NULL; v = v->next) {
		if (v->isVisit == FALSE) {
			name = v->vName; // �湮 ���� ������ �̸��� vName���ٰ� �־���
			break;
		}
	}
	for (v = G->vHead; v != NULL; v = v->next) {
		if ((v->isVisit == FALSE) && (dist[v->vName - 97] < dist[name - 97])) {
			name = v->vName;
		}
	}
	return name; // �湮���� ���� ���� �� ���� ����� ������ ������
}

void prim(GraphType* G, element vName, int dist[]) {
	Vertex* v = findVertex(G, vName);
	AdjacentVertex* a = NULL;
	element name;

	dist[vName - 97] = 0; // ���� ������ 0����

	for (int i = 0; i < G->vCount; i++) {
		name = getMinVertex(G, dist);
		v = findVertex(G, name);
		v->isVisit = TRUE;
		printf("[%c] ", v->vName);

		for (a = v->aHead; a != NULL; a = a->next) { // �湮 ������ �������� ����
			v = findVertex(G, a->aName); // ���������� ���������� ����
			if (v->isVisit == FALSE && a->e->weight < dist[a->aName - 97]) {
				dist[a->aName - 97] = a->e->weight;
			}
		}
	}
}

Vertex* findMin(GraphType* G) {
	Vertex* v = NULL;
	int min = INF;

	for (Vertex* p = G->vHead; p != NULL; p = p->next) {
		if (dist[p->vName - 97] < min && p->isVisit == FALSE) {
			min = dist[p->vName - 97];
			v = p; // dist�� �ּڰ��� �Ǵ� ������ �����Ѵ�
		}
	}

	return v;
}

void dijkstra(GraphType* G, element vName) {
	Vertex* v = NULL;
	AdjacentVertex* a = NULL;

	dist[vName - 97]=0; // ���� ���� �ε����� 0����

	for (int i = 0; i < G->vCount; i++) { // ���� ������ŭ �ݺ�
		v = findMin(G); // �ִܰŸ� ������
		v->isVisit = TRUE;
		printf("[%c(%d)] ", v->vName, dist[v->vName - 97]); // �Դ� ���ٰ� ����� ���ֱ�

		for (a = v->aHead; a != NULL; a = a->next) {
			Vertex* w = findVertex(G, a->aName); // ������ ã��
			if (w->isVisit == FALSE) {
				if (dist[v->vName - 97]+(a->e->weight) < dist[a->aName - 97]) { // ���ؼ� ���� �� < �׳� ���� ��
					dist[a->aName - 97] = dist[v->vName - 97] + (a->e->weight);
				}
			}
		}
	}
}

int main() {
	GraphType G;
	initGraph(&G);

	makeVertax(&G, 'a'); makeVertax(&G, 'b'); makeVertax(&G, 'c'); makeVertax(&G, 'd'); makeVertax(&G, 'e'); makeVertax(&G, 'f'); makeVertax(&G, 'g');

	insertEdge(&G, 'a', 'b', 10); insertEdge(&G, 'a', 'g', 7); insertEdge(&G, 'a', 'f', 3);
	insertEdge(&G, 'b', 'd', 9); insertEdge(&G, 'b', 'g', 6);
	insertEdge(&G, 'c', 'd', 2); insertEdge(&G, 'c', 'g', 4);
	insertEdge(&G, 'd', 'g', 10); insertEdge(&G, 'd', 'e', 4); insertEdge(&G, 'd', 'f', 11);
	insertEdge(&G, 'e', 'f', 5);
	insertEdge(&G, 'f', 'g', 2);
	printGraph(&G);

	dijkstra(&G, 'a');
}

*/

// ����Ž��(Ʈ���ƴ� �� ����Ž����)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ����Ž��

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef int element;

typedef struct TreeNode
{
	element key;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

TreeNode* makeNode(element key)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));

	node->key = key;
	node->left = NULL;
	node->right = NULL;

	return node;
}

int getHeight(TreeNode* root)
{
	int height = 0;

	if (root)
		height = 1 + max(getHeight(root->left), getHeight(root->right));

	return height;
}

int getBalance(TreeNode* root)
{
	if (root == NULL)
		return 0;

	return getHeight(root->left) - getHeight(root->right);
}

TreeNode* rotateLeft(TreeNode* p) {
	TreeNode* c = p->right;
	p->right = c->left;
	c->left = p;

	return c;
}

TreeNode* rotateRight(TreeNode* p) {
	TreeNode* c = p->left;
	p->left=c->right;
	c->right = p;
	
	return c;
}

TreeNode* insertNode(TreeNode* root, element key)
{
	if (root == NULL)
		return makeNode(key);

	if (key < root->key)
		root->left = insertNode(root->left, key);
	else if (key > root->key)
		root->right = insertNode(root->right, key);

	int balance = getBalance(root);

	if (balance > 1 && key < root->left->key) { // LL: �ð���� ȸ�� 
		return rotateRight(root);
	}
	if (balance<-1 && key>root->right->key) { // RR: �ݽð���� ȸ��
		return rotateLeft(root);
	}
	if (balance > 1 && key > root->left->key) { // LR: �ݽð� �� ��, �ð���� ȸ��
		root->left=rotateLeft(root->left);
		return rotateRight(root);
	}
	if (balance < -1 && key < root->right->key) { // RL: �ð���� ȸ�� �ѹ�
		root->right=rotateRight(root->right);
		return rotateLeft(root);
	}

	return root;
}

void preOrder(TreeNode* root)
{
	if (root)
	{
		printf("[%d] ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void display(TreeNode* root, int key)
{
	printf("[Insert %d] : ", key);
	preOrder(root);
	printf("\n");
}

int main()
{
	TreeNode* root = NULL;

	int data[] = { 7, 8, 9, 2, 1, 5, 3, 6, 4 };

	for (int i = 0; i < 9; i++)
	{
		root = insertNode(root, data[i]);
		display(root, data[i]);
	}

	return 0;
}

*/

/*����*/

#define N 10

void selectionSort(int A[])
{
	printf("Before Sort : ");
	for (int i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n");

	printf("\n<<<<<<<<<<<< Selection Sorting... >>>>>>>>>>>>\n");

	for (int i = 0; i <= N - 2; i++)
	{
		int min = i;
		for (int j = i + 1; j <= N - 1; j++)
			if (A[j] < A[min])
				min = j;

		int temp = A[min];
		A[min] = A[i];
		A[i] = temp;

		printf(" %d Pass >> ", i + 1);
		for (int i = 0; i < N; i++)
			printf("%d ", A[i]);
		printf("\n");
	}
}

void insertionSort(int A[])
{
	printf("Before Sort : ");
	for (int i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n");

	printf("\n<<<<<<<<<<<< insertion Sorting... >>>>>>>>>>>\n");

	for (int i = 1; i <= N - 1; i++)
	{
		int key = A[i];

		int j = i - 1;
		while (j >= 0 && A[j] > key) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;

		printf(" %d Pass >> ", i);
		for (int i = 0; i < N; i++)
			printf("%d ", A[i]);
		printf("\n");
	}
}


int main() {
	int A[N];
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		A[i] = rand() % 100;
	}
	// selectionSort(A);
	insertionSort(A);
}
