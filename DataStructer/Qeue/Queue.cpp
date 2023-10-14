#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


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



int main()
{

    Queue();

    return 0;

}