#include <iostream>

struct stack* s = (struct stack*) malloc(sizeof(struct stack*));

struct stack
{
    int data;
    struct stack *next;
};

void push(int data)
{

    struct stack* node = (struct stack*) malloc(sizeof(struct stack*));

    node->data = data;

    node->next = s;

    s = node;

}

void pop()
{
    struct stack *ptr=s,*ptr1;
    int i;
    while(ptr->next != nullptr)
    {
        ptr1 = ptr;
        ptr = ptr->next;

    }

    ptr1 ->next = ptr ->next;
    free(ptr);

}

void print()
{
    struct stack *t = s;

    while( t->next != nullptr)
    {
        std::cout << t->data << std::endl;
        t = t->next;
    }


}

int main()
{
    push(1);
    push(2);
    push(3);

    print();

    pop();

    std::cout << "---------------" << std::endl;

    print();

}