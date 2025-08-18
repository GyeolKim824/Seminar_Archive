#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define M 13

typedef struct HashNode
{
    int key;
    struct HashNode* next;
}HashNode;


void init(HashNode* H)
{
    for (int i = 0; i < M; i++)
    {
        H[i].key = 0;
        H[i].next=NULL;
    }
}


int h(int key)
{
    return key % M;
}


void insertItem(HashNode* H, int key)
{
    int b = h(key);
    HashNode* node = (HashNode*)malloc(sizeof(HashNode));
    node->key = key;
    node->next = H[b].next;
    H[b].next = node;
}

void printHash(HashNode* H)
{
    HashNode* p;
    for (int i = 0; i < M; i++) {
        printf("H[%02d] : ", i);
        for (p = H[i].next; p != NULL; p = p->next) {
            printf("[%d] ", p->key);
        }
        printf("\n");
    }
}

int main()
{
    HashNode H[M];
    init(H);

    srand(time(NULL));

    for (int i = 0; i < 20; i++) {
        insertItem(H, rand() % 90 + 10);
    }
    printHash(H);
}
