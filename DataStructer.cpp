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

int push(struct Stack** r,int data)
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


int main()
{
    // An algorithm is a set of instructions to be followed to solve a problem.
    // two aspects of algorithmic performance : running time and space




    return 0;

}