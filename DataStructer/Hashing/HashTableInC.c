#include <stdio.h>
#include <stdlib.h>

int hashFun(int data, int cap);

struct Node
{
    int key;
    int data;
    struct Node* nextNode;
};

struct TableRow
{
    int size;
    struct Node* next;
};

struct HashTable
{
    int count;
    int capacity;
    struct TableRow* next;

};
struct HashTable *h = NULL;

struct Node* CreateNode(int data)
{

    struct Node* node = (struct Node *)malloc(sizeof(struct Node));

    node->key = hashFun(data,h->capacity);
    node->data = data;
    node->nextNode = NULL;
    return node;

}
void CreateHashTable(int size)
{

    h = (struct HashTable*) malloc(sizeof(struct HashTable));
    h->count = 0;
    h->capacity = size;
    h->next = (struct TableRow*) malloc(sizeof(struct TableRow) * h->capacity);

    for (int i = 0; i < h->capacity; ++i) {
        h->next[i].next = NULL;
        h->next[i].size = 0;
    }

}
void insert(struct Node* node)
{
    int index = node->key;
    int data = node->data;

    node->nextNode = h->next[index].next;
    h->next[index].next = node;
    h->next[index].size++;
    h->count++;

}

int main()
{
    CreateHashTable(10);

    insert(CreateNode(10));
    insert(CreateNode(10));
    printf("%d",h->next->next->data);
    printf("%d",h->next->next->nextNode->data);

}

int hashFun(int data, int cap)
{
    return data % cap;
};
