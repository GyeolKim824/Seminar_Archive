#include<stdio.h>
#include<stdlib.h>

typedef int element;

/*
typedef struct TreeNode {
	element data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

TreeNode* makeNode(element data, TreeNode* left, TreeNode* right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = data;
	node->left = left;
	node->right = right;

	return node;
}
*/

/* ��ȯ ȣ���� �̿��� ��ȸ

void preOrder(TreeNode* root) {
	if (root) {
		printf("[%d] ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(TreeNode* root) {
	if (root) {
		inOrder(root->left);
		printf("[%d] ", root->data);
		inOrder(root->right);
	}
}

void postOrder(TreeNode* root) {
	if (root) {
		postOrder(root->left);
		postOrder(root->right);
		printf("[%d] ", root->data);
	}
}

int main() {
	TreeNode* N4 = makeNode(1, NULL, NULL);
	TreeNode* N6 = makeNode(16, NULL, NULL);
	TreeNode* N7 = makeNode(25, NULL, NULL);
	TreeNode* N2 = makeNode(4, N4, NULL);
	TreeNode* N3 = makeNode(20, N6, N7);
	TreeNode* N1 = makeNode(15, N2, N3);

	printf("Pre: "); preOrder(N1); printf("\n");
	printf("In: "); inOrder(N1); printf("\n");
	printf("Post: "); postOrder(N1); printf("\n");
}

*/

/* ������ ����� ���� ��ȸ

#define SIZE 10

typedef struct StackType {
	int top;
	TreeNode* data[SIZE];
}StackType;

void initStack(StackType*S){
	S->top = -1;
}

void push(StackType* S, TreeNode*e) {
	if (S->top < SIZE - 1) {
		S->data[++S->top] = e;
	}
	else {
		return;
	}
}

TreeNode* pop(StackType* S) {
	TreeNode* e = NULL;

	if (S->top >= 0) {
		e = S->data[S->top--];
	}
		return e;
}

void iterInOrder(TreeNode* root) {
	StackType S;
	initStack(&S);
	
	while (1) {
		for (; root != NULL; root = root->left) {
			push(&S, root);
		}
		root = pop(&S);

		if (root == NULL) {
			break;
		}

		printf("[%d] ", root->data);
		root = root->right;
	}
}


int main() {
	TreeNode* N4 = makeNode(1, NULL, NULL);
	TreeNode* N6 = makeNode(16, NULL, NULL);
	TreeNode* N7 = makeNode(25, NULL, NULL);
	TreeNode* N2 = makeNode(4, N4, NULL);
	TreeNode* N3 = makeNode(20, N6, N7);
	TreeNode* N1 = makeNode(15, N2, N3);

	// printf("Pre: "); preOrder(N1); printf("\n");
	printf("Iter In: "); iterInOrder(N1); printf("\n");
	// printf("Post: "); postOrder(N1); printf("\n");
}

*/

/* ť�� ����� ���� ��ȸ

#define SIZE 100

typedef struct QueueType {
	TreeNode* data[SIZE];
	int front, rear;
}QueueType;

void initQueue(QueueType* Q) {
	Q->front = Q->rear = 0;
}

int isQueueEmpty(QueueType* Q) {
	return Q->rear == Q->front;
}

int isQueueFull(QueueType* Q) {
	return Q->front == (Q->rear + 1) % SIZE;
}

void enqueue(QueueType* Q, TreeNode* e) {
	if (isQueueFull(Q)) {
		return;
	}
	else {
		Q->rear = (Q->rear + 1) % SIZE;
		Q->data[Q->rear] = e;
	}
}

TreeNode* dequeue(QueueType* Q) {
	if (isQueueEmpty(Q)) {
		return NULL;
	}
	else {
		TreeNode* e = NULL;
		Q->front = (Q->front + 1) % SIZE;
		return Q->data[Q->front];
	}
}

void levelOrder(TreeNode* root) {
	QueueType Q;
	initQueue(&Q);

	if (root == NULL) {
		return;
	}

	enqueue(&Q, root);

	while (!isQueueEmpty(&Q)) {
		TreeNode* x = dequeue(&Q);
		if (x) {
			printf("[%d] ", x->data);
		}
		if (x->left) {
			enqueue(&Q, x->left);
		}
		if (x->right) {
			enqueue(&Q, x->right);
		}
	}
}

int main() {
	TreeNode* N4 = makeNode(1, NULL, NULL);
	TreeNode* N6 = makeNode(16, NULL, NULL);
	TreeNode* N7 = makeNode(25, NULL, NULL);
	TreeNode* N2 = makeNode(4, N4, NULL);
	TreeNode* N3 = makeNode(20, N6, N7);
	TreeNode* N1 = makeNode(15, N2, N3);

	printf("Level: "); levelOrder(N1);
}

*/

/* ����Ž��Ʈ�� */
typedef struct TreeNode {
	element key;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

TreeNode* makeNode(element key) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void preOrder(TreeNode* root) {
	if (root) {
		printf("[%d] ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

TreeNode* insertNode(TreeNode* root, element key) {
	if (root == NULL) {
		return makeNode(key);
	}
	if (key < root->key) {
		root->left = insertNode(root->left, key);
	}
	else if (key > root->key) {
		root->right = insertNode(root->right, key);
	}
	else {
		return NULL;
	}

	return root;
}

TreeNode* minValueNode(TreeNode* root) {
	TreeNode* p = root;
	while (p->left != NULL) {
		p = p->left;
	}
	return p;
}

TreeNode* deleteNode(TreeNode* root, element key) {
	if (root == NULL) {
		return NULL;
	}
	if (key < root->key) {
		root->left = deleteNode(root->left, key);
	}
	else if (key > root->key) {
		root->right = deleteNode(root->right, key);
	}
	else { // Ű ���� ���� ��带 �߰�
		if (root->left == NULL) { // ������ ��尡 �־��
			TreeNode* tmp = root->right;
			free(root);
			return tmp;
		}
		else if (root->right == NULL) { // ���� ��尡 �־��
			TreeNode* tmp = root->left;
			free(root);
			return tmp;
		}
		else { // �� �� �־��
			TreeNode* tmp = minValueNode(root->right);
			root->key = tmp->key;
			root->right = deleteNode(root->right, tmp->key);
		}
	}


	return root;
}

int maxValue(TreeNode* left, TreeNode* right) {
	
}

int getHeight(TreeNode* root) {
	int height = 0;
	if (root != NULL) {
		height = 1 + maxValue(getHeight(root->left),getHeight(root->right);
	}
	return height;
}

int main() {
	TreeNode* root = NULL;

	root = insertNode(root, 35); root = insertNode(root, 68);
	root = insertNode(root, 99); root = insertNode(root, 18);
	root = insertNode(root, 7); root = insertNode(root, 3);
	root = insertNode(root, 12); root = insertNode(root, 26);
	root = insertNode(root, 22); root = insertNode(root, 30);
	preOrder(root); printf("\n"); getchar();

	// root = deleteNode(root, 35); preOrder(root); printf("\n");  getchar();

	printf("%d", getHeight(root));

}
