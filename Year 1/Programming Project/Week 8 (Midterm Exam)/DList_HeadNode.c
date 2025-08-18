#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct DListNode {
	struct DListNode* pre;
	element data;
	struct DListNode* next;
}DListNode;

void initList(DListNode* H, DListNode* T) {
	H->next = T;
	T->pre = H;
}

void printList(DListNode* H, DListNode* T) {
	for (DListNode* tmp = H->next; tmp != T; tmp = tmp->next) {
		printf("[%d]<=>  ", tmp->data);
	}
	printf("\n");
}

int countSize(DListNode* H, DListNode* T) {
	int size = 0;
	for (DListNode* tmp = H->next; tmp != T; tmp = tmp->next) {
		size += 1;
	}
	return size;
}

void insertLast(DListNode* H, DListNode* T, element data) {
	DListNode* new = (DListNode*)malloc(sizeof(DListNode));
	new->data = data;

	new->next = T;
	new->pre = T->pre;
	T->pre->next = new;
	T->pre = new;
	
	H->pre = new;
}

void insertFirst(DListNode* H, DListNode* T, element data) {
	DListNode* new = (DListNode*)malloc(sizeof(DListNode));
	new->data = data;

	new->next = H->next;
	new->pre = H;
	H->next->pre = new;
	H->next = new;

	T->next = new;
}


void insertList(DListNode* H, DListNode*T, int pos, element data) {
	DListNode* new = (DListNode*)malloc(sizeof(DListNode));
	new->data = data;

	if (pos <= 1) {
		insertFirst(H, T, data);
	}
	else if (pos>=countSize(H,T)) {
		insertLast(H, T, data);
	}
	else {
		DListNode* tmp = H;
		for (int i = 1; i < pos; i++) {
			tmp = tmp->next;
		}
		new->next = tmp->next;
		new->pre = tmp;
		tmp->next->pre = new;
		tmp->next = new;
	}
}

element deleteLast(DListNode* H, DListNode* T) {
	DListNode* tmp = T->pre;
	element e = tmp->data;

	T->pre = tmp->pre;
	tmp->pre->next = T;

	H->pre = T->pre;	

	free(tmp);
	return e;
}

element deleteFirst(DListNode* H, DListNode* T) {
	DListNode* tmp = H->next;
	element e = tmp->data;

	H->next = tmp->next;
	tmp->next->pre = H;

	T->next = H->next;
	
	free(tmp);
	return e;
}

element deleteList(DListNode* H, DListNode*T, int pos) {
	if (pos <= 1) {
		deleteFirst(H, T);
	}
	else if (pos >= countSize(H, T)) {
		deleteLast(H, T);
	}
	else {
		DListNode* tmp = H;
		for (int i = 0; i < pos; i++) {
			tmp = tmp->next;
		}
		DListNode* p = tmp->next;
		element e = p->data;

		tmp->next = p->next;
		p->pre = p->pre;

		free(p);
		return e;
	}
}

void deleteKey(DListNode* H, DListNode* T, element k) {
	DListNode* tmp = H->next;
	int pos = 1;

	while (tmp != T) {
		if (tmp->data == k) {
			deleteList(H, T, pos);
			pos--;
			tmp = tmp->next;
		}
		else {
			tmp = tmp->next;
			pos++;
		}
	}
}

int main() {
	DListNode* H = (DListNode*)malloc(sizeof(DListNode));
	DListNode* T= (DListNode*)malloc(sizeof(DListNode));;
	initList(H, T);

	insertList(H, T, 1, 10);  
	insertList(H, T, 2, 20); 
	insertList(H, T,  3, 20); 
	insertList(H, T, 1, 10); 
	insertList(H, T, 5000, 20); 
	insertList(H, T, 4, 20); 
	insertList(H, T, 5, 10); 

	deleteKey(H, T, 10); printList(H, T);

}
