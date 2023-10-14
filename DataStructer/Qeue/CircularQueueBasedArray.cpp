#include <iostream>
#define N 5
int i = 0, range;
int Queue[N];

void Enqueue(int item)
{
    range++;
    if(i >= N)
    {
        i %= N;
        range = N;
    }

    Queue[i] = item;

    i++;

}

void Display()
{
    for (int j = 0; j < range; ++j) {
        std::cout << Queue[j] << std::endl;
    }
}
int main()
{
    Enqueue(5);
    Enqueue(6);
    Enqueue(67);
    Enqueue(676);
    Enqueue(6764);
    Enqueue(67645);
    Enqueue(676451);
    Display();
}