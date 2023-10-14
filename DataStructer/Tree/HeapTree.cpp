/*
#include <iostream>
struct heap
{
    char c;
    struct heap *heap;
};

struct heap* insert(struct heap* node, std::string data, char c)
{
    if(node == nullptr)
    {
        struct heap *root = (struct heap*) malloc(sizeof(struct heap*));

        root->heap = nullptr;
        root->c = c;
        return root;
    }

    node->heap = insert(node->heap, data,c);

    return node;

}

void print(struct heap *t)
{
    if(t == nullptr)
        return;

    print(t->heap);

}

int main()
{

    struct heap *d = nullptr;

    d = insert(d,"asd",'/');

    print(d);

}

*/
#include <iostream>
///////// will updated

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << std::endl;
    }
}

void heap(int arr[],int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        std::cout << arr[i] << " ";

}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);
    heap(arr,N);

    //    print(arr);


}