#include <iostream>
#define N 500

int Q[N];
int i;

void Enqueue()
{
    Q[i] = i;
    i++;
}
void Dequeue()
{

    for (int k = 0; k < i; ++k)
        Q[k - 1] = Q[k];
    i--;

}
void Display()
{
    for (int j = 0; j < i; ++j) {
        std::cout << Q[j] << std::endl;
    }
}
int main()
{
    Enqueue();
    Enqueue();
    Enqueue();
    Dequeue();
    Display();

}