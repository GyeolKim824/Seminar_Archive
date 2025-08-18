#include<stdio.h>
#include<stdlib.h>

/* �������Ḯ��Ʈ

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* next; // ���� ���� ������ : �ڱ����� ����ü
}ListNode;

typedef struct ListType {
	ListNode* tail;
	int size;
}ListType;

void init(ListType* L) {
	L->tail = NULL;
	L->size = 0;
}

int isEmpty(ListType* L) {
	return L->tail == NULL;
	// return L->size==0; �� ���� �����ϴ�
}

void print(ListType* L) {
	if (isEmpty(L)) {
		return;
	}

	ListNode* tmp = L->tail->next;
	for (int i = 1; i <= L->size; i++) {
		printf("[%d] -> ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

void print_2(ListType* L) {
	if (isEmpty(L)) {
		return;
	}
	ListNode* p = L->tail;
	do{
		printf("[%d] -> ", p->next->data);
		p = p->next;
	}
	while (p!= L->tail);
	printf("\n");
}

void insertLast(ListType* L, element e) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = e;

	if (isEmpty(L)) {
		L->tail = node;
		L->tail->next = node;
	}
	else {
		node->next = L->tail->next;
		L->tail->next = node;
		L->tail = node;
	}
	L->size++;
}

void insertFirst(ListType* L, element e) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = e;

	if (isEmpty(L)) {
		L->tail = node;
		L->tail->next = node;
	}
	else {
		node->next = L->tail->next;
		L->tail->next = node;
	}
	L->size++;
}

void insertPosition(ListType* L, int pos, element e) {
	if (pos <= 1) {
		insertFirst(L, e);
	}
	else if (pos >= L->size) {
		insertLast(L, e);
	}
	else {
		ListNode* p = L->tail->next;
		for (int i = 1; i <= pos - 1; i++) {
			p = p->next;
		}

	}
}

element deleteFirst(ListType* L) {
	if (isEmpty(L)) {
		return -1;
	}
	ListNode* p = L->tail;
	ListNode* q = p->next;
	element e = q->data;
	
	if (p == q) { // ���� �ÿ� ����Ʈ�� ��� ���
		L->tail = NULL;
	}
	else {
		p->next = q->next;
	}
	L->size--;
	free(q);
	return e;
}

element deleteLast(ListType* L) {
	if (isEmpty(L)) {
		return -1;
	}
	ListNode* p = L->tail;
	ListNode* q = p->next;
	element e = p->data;

	if (p == q) { // ���� �ÿ� ����Ʈ�� ��� ���
		L->tail = NULL;
	}
	else {
		while (q->next != p) {
			q = q->next;
		}
		q->next = p->next;
		L->tail = q;
	}
	L->size--;
	free(p);
	return e;
}

int main() {
	ListType L;
	init(&L);
	
	insertFirst(&L, 10);
	print_2(&L);
	insertLast(&L, 40);
	print_2(&L);
	insertLast(&L, 20);
	print_2(&L);
	insertLast(&L, 60);
	print_2(&L);
	insertLast(&L, 70);
	print_2(&L);

	printf("[%d] is deleted.\n", deleteFirst(&L)); print_2(&L);
	printf("[%d] is deleted.\n", deleteLast(&L)); print_2(&L);
}

*/

/* ��� �����͸� ����ϴ� ���߿��Ḯ��Ʈ

typedef int element;

typedef struct DListNode {
	struct DListNode* prev;
	element data;
	struct DListNode* next;
}DListNode;

typedef struct DListType {
	DListNode* head;
	int size;
	DListNode* tail;
}DListType;

void init(DListType* DL) {
	DL->tail = NULL;
	DL->head = NULL;
	DL->size = 0;
}

void print(DListType* DL) {
	for (DListNode* p = DL->head; p != NULL; p = p->next) {
		printf("[%d]<->", p->data);
	}
	printf("\n");
}

int isEmpty(DListType* DL) {
	return DL->tail == NULL || DL->size == 0;
}

void insertFirst(DListType* DL, element e) {
	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
	node->data = e;
	DListNode* p = DL->head;
	
	node->prev = NULL;
	node->next = p;

	if (isEmpty(DL)) {
		DL->head = DL->tail = node;
	}
	else {
		p->prev = node;
		DL->head = node;
	}
	DL->size++;
}

void insertLast(DListType* DL, element e) {
	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
	DListNode* p = DL->tail;
	node->data = e;

	node->data = e;
	node->prev = p;
	node->next = NULL;

	if (isEmpty(DL)) {
		DL->head = DL->tail = node;
	}
	else {
		p->next = node;
		DL->tail = node;
	}
	DL->size++;
}

void insert(DListType* DL, int pos, element e) {
	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
	DListNode* p = DL->head;

	if (pos == 1) {
		insertFirst(DL, e);
	}
	else if (pos == DL->size + 1) {
		insertLast(DL, e);
	}
	else {
		for (int i = 1; i < pos; i++) {
			p = p->next;
		}
		node->data = e;
		node->prev = p->prev;
		node->next = p;
		p->prev->next = node;
		p->prev = node;
		DL->size++;
	}
}

int main() {
	DListType DL;
	init(&DL);

	insertFirst(&DL, 10); print(&DL);
	insertFirst(&DL, 30); print(&DL);
	insertFirst(&DL, 20); print(&DL);
	
	insertLast(&DL, 40); print(&DL);
	insertLast(&DL, 50); print(&DL);

	insert(&DL, 1, 60); print(&DL);
	insert(&DL, 3, 80); print(&DL); 
	insert(&DL, DL.size+1, 70); print(&DL);
}
*/

/* ��� ��带 ����ϴ� ���߿��Ḯ��Ʈ */

typedef int element;

typedef struct DListNode {
	struct DListNode* prev;
	element data;
	struct DListNode* next;
}DListNode;

void init (DListNode* H, DListNode* T) {
	H->next = T;
	T->prev = H;
}

void insert(DListNode* H, int pos, element e) {
	DListNode* p = H;
	
	for (int i = 1; i < pos; i++) { // ������ ������ �̵�
		p = p->next;
	}

	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
	node->data = e;
	node->prev = p;
	node->next = p->next;
	p->next->prev = node;
	p->next = node;

}

element deletePosition(DListNode* H, int pos) {
	DListNode* p = H;
	for (int i = 0; i < pos; i++) { // �����Ǳ��� �̵�
		p = p->next;
	}
	element e = p->data;
	p->prev->next = p->next;
	p->next = p->prev->next;
	return e;
}

void print(DListNode* H,DListNode* T){
	for (DListNode* p = H->next; p != T; p = p->next) {
		printf("[%d] <->", p->data);
	}
	printf("\n");
}

int main() {
	DListNode* H = (DListNode*)malloc(sizeof(DListNode));
	DListNode* T = (DListNode*)malloc(sizeof(DListNode));
	init(H, T);

	insert(H, 1, 10); print(H, T);
	insert(H, 1, 30); print(H, T);
	insert(H, 2, 40); print(H, T);
	insert(H, 2, 60); print(H, T);
	insert(H, 3, 70); print(H, T);
	insert(H, 5, 20); print(H, T);

	deletePosition(H, 5); print(H, T);
	
}
