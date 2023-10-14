#include <iostream>

struct Stack *stack = NULL;

struct Stack
{
    int item;
    struct Stack *next;
};

void push(int item)
{
    struct Stack *ptr = (struct Stack*) malloc(sizeof(struct Stack*));

    ptr->item = item;
    ptr->next = stack;
    stack = ptr;
}

void pop()
{
    struct Stack *ptr = stack;

    stack = stack->next;
    free(ptr);

}

void display()
{
    struct Stack *p = stack;

    while(p != nullptr)
    {
        std::cout << p->item << std::endl;
        p = p->next;
    }
}

int main()
{
    push(31);
    push(31);
    push(31);
    push(31);
    pop();
    display();

    return 0;
}