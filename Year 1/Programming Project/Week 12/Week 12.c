#include<stdio.h>
#include<stdlib.h>

#define N 10
#define TRUE 1
#define FALSE 0
#define INF 1000

typedef char element;
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
			printf("[%c, %d]   ", a->aName,a->e->weight);
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

void makeAdjacentVertex(Vertex* v, element aName,Edge* e) {
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


int vFind(int vertices[], int vNum) {
	if (vertices[vNum] == -1) {
		return vNum;
	}
	while (vertices[vNum] != -1) {
		vNum=vertices[vNum]; // ���� ���տ� �ִ� �������� ����. ��� b(1)�� -1 c(2)�� 1, g�� 2�ε� ���� g�� �������� g->c->b�� �̵��ؼ� -1�� ã��
	}
	return vNum; // �׶� vNum ������
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
		printf("[%c]\n", v->vName);

		for (a = v->aHead; a != NULL; a = a->next) { // �湮 ������ �������� ����
			v = findVertex(G, a->aName); // ���������� ���������� ����
			if (v->isVisit == FALSE && a->e->weight<dist[a->aName-97]) {
				dist[a->aName - 97] = a->e->weight;
			}
		}
	}
}

int main() {
	GraphType G;
	initGraph(&G);

	makeVertax(&G, 'a'); makeVertax(&G, 'b'); makeVertax(&G, 'c'); makeVertax(&G, 'd'); makeVertax(&G, 'e'); makeVertax(&G, 'f'); makeVertax(&G, 'g');

	insertEdge(&G, 'a', 'b',10); insertEdge(&G, 'a', 'g',3); insertEdge(&G, 'a', 'f', 7);
	insertEdge(&G, 'b', 'd',9); insertEdge(&G, 'b', 'g',6);
	insertEdge(&G, 'c', 'd',2); insertEdge(&G, 'c', 'g', 4);
	insertEdge(&G, 'd', 'g',10); insertEdge(&G, 'd', 'e', 4); insertEdge(&G, 'd', 'f',11);
	insertEdge(&G, 'e', 'f',5); 
	insertEdge(&G, 'f', 'g', 2);
	// printGraph(&G);

	//  Edge* edges[N]; printf("\n"); 
	// incSort(&G, edges); printf("\n");

	// int vertices[N] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	// kruskal(&G, edges, vertices); printf("\n");

    int dist[N] = { INF,INF,INF,INF,INF,INF,INF,INF,INF,INF };
     prim(&G, 'a', dist); printf("\n");
}
