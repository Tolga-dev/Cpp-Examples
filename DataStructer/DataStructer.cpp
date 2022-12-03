#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


struct Stack
{
    int data;
    struct Stack* next;
};

struct Stack* newOne(int data)
{
    struct Stack* stack= (struct Stack*) malloc(sizeof (struct Stack));
    stack->next = NULL;
    stack->data = data;
    return stack;
}

void push(struct Stack** r,int data)
{
    struct Stack* stack = newOne(data);
    stack->next = *r;
    *r = stack;
    printf("pushed to stack \n", data);
}

int pop(struct Stack** r)
{
    struct Stack* t = *r;
    *r = (*r)->next;
    int p = t->data;
    free(t);

    return p;
}

void stack()
{
    struct Stack* r = NULL;

    push(&r, 31);
    push(&r, 3);
    push(&r, 4);
    printf("%d \n",r->data);
    printf("%d \n", pop(&r));
    printf("%d \n", pop(&r));
    printf("%d \n", pop(&r));
    printf("%d \n", pop(&r));
    printf("%d \n",r->data);
}


struct Queue
{
    int capacity,front,rear;
    int* arr;
};

struct Queue* CreateQue(int cap)
{
    struct Queue* q = (struct Queue*) malloc(sizeof(Queue));
    q->capacity = cap;

    q->arr = (int*)malloc(q->capacity * sizeof(int));

    return q;
}

void Enqueue(struct Queue* q, int item)
{
    q->arr[q->rear] = item;
    q->rear = (q->rear + 1) % q->capacity;
}
void Dequeue(struct Queue* q)
{
    for(int i=0; i < q->capacity; i++)
        q->arr[i] = q->arr[i+1];
//    q->front = (q->front + 1)% q->capacity;

}
void Queue()
{
    struct Queue* que = CreateQue(31);

    Enqueue(que, 1235);
    Enqueue(que, 125);
    Enqueue(que, 135);
    Dequeue(que);
    printf("%d \n", que->arr[que->front-2]);
}





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