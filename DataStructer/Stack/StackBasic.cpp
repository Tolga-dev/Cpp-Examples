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
    struct stack* temp = s, *ptr;

    s = s->next;

    free(temp);
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
    push(4);
    print();
    pop();
    pop();
    pop();
    print();

}