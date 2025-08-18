#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/* �迭�� ������ ���Ḯ��Ʈ
# define N 100

typedef int element;

typedef struct ListType {
	element data[N];
	int size;
}ListType;

void init(ListType* L) {
	L->size = 0;
}

int isFull(ListType* L) {
	return L->size == N;
}

int isEmpty(ListType* L) {
	return L->size == 0;
}

void print(ListType* L) {
	for (int i = 0; i <= L->size - 1; i++) {
		printf("[%d] ", L->data[i]);
	}
	printf("\n");
}

void insertLast(ListType* L, element e) {
	if (isFull(L)) {
		printf("FULL!\n");
	}
	else {
		L->data[L->size] = e;
		L->size++;
	}
}

void insert(ListType* L, int pos, element e) {
	if (isFull(L)) {
		printf("FULL!\n");
		return;
	}
	if (pos<0 || pos>L->size) {
		printf("Invalid Position!\n");
		return;
	}
	for (int i = (L->size - 1); i >= pos; i--) {
		L->data[i + 1] = L->data[i];
	}
	L->data[pos] = e;
	L->size++;
}

element deleteLast(ListType* L) {
	if (isEmpty(L)) {
		printf("EMPTY!\n");
		return -1;
	}
	element e = L->data[L->size - 1];
	L->size--;
	return e;
}

element deletePosition(ListType* L, int pos) {
	if (isEmpty(L)) {
		printf("EMPTY!\n");
		return -1;
	}
	if (pos < 0 || pos >= L->size) {
		printf("Invalid Position!\n");
		return -1;
	}
	element e = L->data[pos];
	for (int i = pos; i < (L->size - 1); i++) {
		L->data[i] = L->data[i + 1];
	}
	L->size--;

	return e;
}

int main() {
	ListType L;
	init(&L);

	insertLast(&L, 10); print(&L);
	insertLast(&L, 20); print(&L);
	insertLast(&L, 30); print(&L);
	getchar();

	insert(&L, 1, 40); print(&L);
	insert(&L, 0, 50); print(&L);
	insert(&L, L.size, 60); print(&L);
	getchar();

	printf("[%d] is deleted.\n", deleteLast(&L)); print(&L);
	printf("[%d] is deleted.\n", deletePosition(&L, 1)); print(&L);
}

*/

// ����� ǥ����

typedef char element;

typedef struct ListNode {
	element data;
	struct ListNode* next; // ���� ���� ������ : �ڱ����� ����ü
}ListNode;

typedef struct ListType{
	ListNode* head;
	int size;
	ListNode* tail;
}ListType;

void init(ListType* L) {
	L->head = NULL;
	L->size = 0;
}

int isEmpty(ListType* L) {
	return L->head == NULL;
	// return L->size==0; �� ���� �����ϴ�
}

void print(ListType* L) {
	ListNode* p = L->head;
	for (p=L->head; p!=NULL; p=p->next) {
		printf("%c => ", p->data);
	}
	printf("\b\b\b    \n");
}

void insertFirst(ListType* L, element e) {
	ListNode* node=(ListNode*)malloc(sizeof(ListNode));
	
	node->data = e;
	node->next = L->head;
	L->head = node;
	L->size++;
}

void insertLast(ListType* L, element e) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	
	node->data = e;
	node->next = NULL;

	if (isEmpty(L)) {
		L->head = node;
	}
	else {
		ListNode* p = L->head;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = node;
		L->tail = node;
	}
	L->size++;
}

void insertPosition(ListType* L, int pos, element e) {
	if (pos == 1) {
		insertFirst(L, e);
	}
	else if (pos == L->size + 1) {
		insertLast(L, e);
	}
	else {
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		ListNode* p = L->head;
		node->data = e;

		for (int i = 1; i < pos - 1; i++) {
			p = p->next;
		}
		node->next = p->next;
		p->next = node;

		L->size++;
	}
}

element deleteFirst(ListType* L) {
	ListNode* p = L->head;
	element e = p->data;
	L->head = L->head->next;
	L->size--;
	return e;
}

element deletePosition(ListType* L, int pos) {

	if (pos<1 || pos>L->size) {
		return -1;
	}
	else {
		ListNode* p = L->head;
		ListNode* q;
		element e;
		
		if (pos == 1) {
			e = deleteFirst(L);
		}
		else {
			for (int i = 1; i < pos; i++) {
				q = p;
				p = p ->next;
			}
			e = p->data;
			q->next = p->next;
			free(p);
			L->size--;
			return e;
		}
	}
}

int main() {
	ListType L;
	init(&L);

	insertLast(&L, 'F'); print(&L);

	insertFirst(&L, 'A'); print(&L);
	insertFirst(&L, 'B'); print(&L);
	insertFirst(&L, 'C'); print(&L);
	getchar();

	insertLast(&L, 'D'); print(&L);
	insertLast(&L, 'E'); print(&L);
	insertLast(&L, 'F'); print(&L);
	getchar();

	insertPosition(&L,1, 'G'); print(&L);
	insertPosition(&L,4, 'H'); print(&L);
	insertPosition(&L,L.size+1,'I'); print(&L);
	getchar();

	deleteFirst(&L); print(&L);
	deletePosition(&L, 2); print(&L);
}
