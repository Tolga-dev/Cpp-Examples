#include <iostream>

struct Queue *Queue= nullptr;

struct Queue
{
    int item;
    struct Queue *next;
};

void Enqueue(int item)
{
    struct Queue *ptr = (struct Queue*) malloc(sizeof(struct Queue*));

    ptr->item = item;
    ptr->next = nullptr;

    if(Queue == nullptr)
        Queue = ptr;
    else
    {
        ptr->next = Queue;
        Queue = ptr;
    }
}
void Dequeue()
{
    struct Queue *ptr = Queue;

    Queue = ptr->next;

    free(ptr);
}

void Display()
{
    struct Queue *ptr = Queue;
    while(ptr != nullptr)
    {
        std::cout << ptr->item << std::endl;
        ptr = ptr->next;
    }
}
int main()
{
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    Display();


}