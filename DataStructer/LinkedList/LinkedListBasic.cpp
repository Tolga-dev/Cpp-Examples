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
    while(r != NULL)
    {
        printf("data:  %d \n", r->id);
        r = r->next;
    }
    printf(" finished \n");
}
void DeleteNode(int i)
{
    struct LinkedList *r = head,*n = NULL, *len = head;
    int size;
    while(len != NULL)
    {
        size++;
        len = len->next;
    }
    i = size - i;

    while(i-- > 1)
    {
        n = r;
        r = r->next;

    }
    n->next = r->next;
    free(r);

    printf(" finished \n");

}

int main()
{

    // An algorithm is a set of instructions to be followed to solve a problem.
    // two aspects of algorithmic performance : running time and space
    head = (struct LinkedList*) malloc(sizeof(struct LinkedList));

    printf("start \n");
    Creation(3);
    Creation(354);
    Creation(34);
    Creation(54);
    Creation(35);
    Creation(4);
    DeleteNode(0);
    printNodesData();


    return 0;

}