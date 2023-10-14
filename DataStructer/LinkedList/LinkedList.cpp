#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct LinkedList* head = NULL;
void printNodesData();

struct LinkedList
{
    int data;
    int id;
    struct LinkedList* next;
};

void Creation(int NewGdata)
{
    struct LinkedList* newGen = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    newGen->data = NewGdata;
    newGen->next = head;
    newGen->id = head->id + 1;
    head = newGen;

}

void printNodesData()
{
    struct LinkedList *r = head;
    while(r->next != NULL)
    {
        printf("data:  %d \n", r->data);
        r = r->next;
    }
    printf(" finished \n");
}

void beginInsert(int data)
{
    struct LinkedList *node = (struct LinkedList*) malloc(sizeof(struct LinkedList*));

    node->data = data;
    node->next = head;
    head = node;
}

void DeleteNode(int loc)
{
    struct LinkedList *ptr,*ptr1;
    int i;
    ptr=head;
    for(i=0;i<loc;i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;

        if(ptr == NULL)
        {
            printf("\nCan't delete");
            return;
        }
    }
    ptr1 ->next = ptr ->next;
    free(ptr);
}

int main()
{

    head = (struct LinkedList*) malloc(sizeof(struct LinkedList));

    printf("start \n");
    Creation(3);
    Creation(354);
    Creation(34);
    Creation(54);
    Creation(35);
    Creation(4);
    beginInsert(9);
    printNodesData();
    DeleteNode(2);
    printNodesData();


    return 0;

}
/*
start
data:  34
data:  2
data:  354
data:  3
 finished
data:  34
data:  2
data:  3
 finished
 */