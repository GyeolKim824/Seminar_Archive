#include<stdio.h>
#include<stdlib.h>

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

void initList(DListType* DL) {
	DL->head = NULL;
	DL->size = 0;
	DL->tail = NULL;
}

int isListEmpty(DListType* DL) {
	return DL->size==0;
}

void printList(DListType* DL) {
	if (isListEmpty(DL)) {
		printf("EMPTY!!");
	}
	DListNode* p = DL->head;
	for (int i = 0; i < DL->size;i++) {
		printf("[%d] <=> ", p->data);
		p = p->next;
	}
	printf("\n");
}

void insertLast(DListType* DL, element e) {
	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
	node->data = e;

	if (isListEmpty(DL)) {
		DL->head = node;
		DL->tail = node;
	}
	else {
		node->prev = DL->tail;
		node->next = DL->head;
		DL->tail->next = node;
		DL->head->prev = node;
		DL->tail = node;
	}

	DL->size++;
}

void insertFirst(DListType* DL, element e) {
	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
	node->data = e;

	if (isListEmpty(DL)) {
		DL->head = node;
		DL->tail = node;
	}
	else {
		node->prev = DL->tail;
		node->next = DL->head;
		DL->tail->next = node;
		DL->head = node;
	}
	DL->size++;
}

void insertPos(DListType* DL,int pos, element e) {

	if (pos <= 1) {
		insertFirst(DL, e);
	}
	else if (pos > DL->size) {
		insertLast(DL, e);
	}
	else {
		DListNode* node = (DListNode*)malloc(sizeof(DListNode));
		node->data = e;
		DListNode* p=DL->head;
		for (int i = 0; i < pos - 2; i++) {
			p = p->next;
		}
		DListNode* q = p->next;

		node->prev = p;
		node->next = q;
		q->prev = node;
		p->next = node;

		DL->size++;
	}
}

element deleteLast(DListType* DL) {

	if (isListEmpty(DL)) {
		printf("EMPTY!!");
		return -1;
	}
	else {
		element e = DL->tail->data;

		DL->tail = DL->tail->prev;
		DL->head->prev = DL->tail;
		DL->tail->next = DL->head;

		DL->size--;
		return e;
	}
}

element deleteFirst(DListType* DL) {

	if (isListEmpty(DL)) {
		printf("EMPTY!!");
		return -1;
	}
	else {
		element e = DL->head->data;

		DL->tail->next = DL->head->next;
		DL->head = DL->head->next;
		DL->head->prev = DL->tail;

		DL->size--;
		return e;
	}
}

element deletePos(DListType* DL, int pos) {
	
	if (pos == 1) {
		return deleteFirst(&DL);
	}
	else if (pos >= DL->size) {
		return deleteLast(&DL);
	}
	else {
		DListNode* p = DL->head;
		for (int i = 0; i < pos - 2; i++) {
			p=p->next;
		}
		DListNode* q = p->next->next;
		element e = p->next->data;

		p->next = q;
		q->prev = p;

		DL->size--;
		return e;
	}
}

void insertTail(DListType* DL, int pos, element e) {
	if (isListEmpty(&DL)) {
		printf("EMPTY!!");
	}
	else if (pos>=DL->size) { // �� �� ����
		insertFirst(DL, e);
	}
	else if (pos <= 1) { // �� �� ����
		insertLast(DL, e);
	}
	else { // �߰� ����
		DListNode* node = (DListNode*)malloc(sizeof(DListNode));
		node->data = e;

		DListNode* p = DL->tail;
		for (int i = 0; i < pos - 2; i++) {
			p = p->prev;
		}
		DListNode* q = p->prev;

		node->next = p;
		node->prev = q;
		p->prev = node;
		q->next = node;

		DL->size++;
	}
}

void printRotate(DListType* DL, int count) {
	DListNode* p = DL->head;

	for (int i = 0; i < count; i++) {
		printf("[%d] <=> ", p->data);
		p = p->next;
	}
	printf("\n");
}

void deleteKey(DListType* DL, element k) {
	DListNode* p = DL->head;
	int pos = 1;
	
	while (p != DL->tail) {
		if (p->data == k) {
			deletePos(DL, pos);
			pos--;
		}
		p = p->next;
		pos++;
	}

	if (DL->tail->data == k) {
		deletePos(DL, DL->size);
	}
}

void switchElement(DListType* DL, int pos1, int pos2, char direction) {
	DListNode* p = DL->head->next;
	for (int i = 1; i < pos1 - 1; i++) {
		p = p->next;
	}

	DListNode* q = p;
	if (direction == 'r') {
		for (int i = 0; i < pos2; i++) {
			q = q->next;
		}
		int tmp = q->data;
		q->data = p->data;
		p->data = tmp;
	}
	else if (direction == 'l') {
		for (int i = 0; i < pos2; i++) {
			q = q->prev;
		}
		int tmp = q->data;
		q->data = p->data;
		p->data = tmp;
	}
}

int main() {
	DListType DL;
	initList(&DL); printList(&DL);

	insertLast(&DL, 20);
	insertLast(&DL, 30);
	insertLast(&DL, 50);
	insertLast(&DL, 10);
	insertLast(&DL, 40);
	printList(&DL);

	printf("[%d]", DL.head->prev->data);
	printf("[%d]\n", DL.tail->next->data);

	insertTail(&DL, 1, 10); 
	insertTail(&DL, 3, 60); 
	insertTail(&DL, 4, 50); printList(&DL);

	printRotate(&DL, 10); 
	printList(&DL);

	deleteKey(&DL, 50); printList(&DL);

	switchElement(&DL, 2, 3, 'r'); printList(&DL);
	switchElement(&DL, 4, 2, 'l'); printList(&DL);

}
