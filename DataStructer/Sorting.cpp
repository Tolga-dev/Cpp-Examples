#include <iostream>
#include <chrono>
#include <array>
#include <time.h>
#include <math.h>

auto s = std::chrono::system_clock::now();
auto f = std::chrono::system_clock::now();

void swap (int *a, int *b)
{
    for (int i = 1 ; i ; i <<= 1)
    {
        if ((*a & i) != (*b & i))
        {
            *a ^= i;
            *b ^= i;
        }
    }

}

void CLockStart()
{
    s = std::chrono::system_clock::now();
}
void CLockEnd()
{
    f = std::chrono::system_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(f-s).count() << std::endl;
    std::cout << std::chrono::duration_cast<std::chrono::seconds>(f-s).count() << std::endl;
}

void insertion()
{
    srand(time(NULL));

    std::array<int, 4> arr;


    for(auto i = 0; i < arr.size(); i++)
        arr[i] = rand() % 10 + 1;

    for(auto i : arr)
        std::cout << i << " " ;
    std::cout << std::endl;


    int key, step;
    CLockStart();
    for(int i = 1; i < arr.size(); i++)
    {
        key = arr[i];
        step = i-1;

        while(step >= 0 && arr[step] > key)
        {

            arr[step+1] = arr[step];
            step--;
        }

        arr[step+1] = key;

    }
    CLockEnd();

    for(auto i : arr)
        std::cout << i << " "  ;
    std::cout << std::endl;

}

void selectionSort(std::array<int, 10> D) {
    int n = D.size();

    int i, index, j, min;

    CLockStart();
    for (i = 0; i < (n-1); i++) {
        min = D[n-1];
        index = n-1;
        for (j = i; j < (n-1); j++){
            if (D[j] < min){
                min = D[j];
                index = j;
            }
        }
        if (i != index){
            D[index] = D[i];
            D[i] = min;
        }
    }
    CLockEnd();

    for(auto i : D)
        std::cout << i << " "  ;
    std::cout << std::endl;


}
void selection()
{
    srand(time(NULL));

    std::array<int, 10> arr;


    for(auto i = 0; i < arr.size(); i++)
        arr[i] = rand() % 100 + 1;


    for(auto i : arr)
        std::cout << i << " " ;
    std::cout << std::endl;

//////////////////////
    selectionSort(arr);
//////////////////////

/////////////////////////
    int key,n;
    CLockStart();
    for(int i = 0; i < arr.size(); i++)
    {
        key = arr[i];
        n = i;
        for(int j = i; j < arr.size(); j++)
        {
            if(arr[j] < key)
            {
                key = arr[j];
                n = j;
            }

        }
        if(i != n)
        {

            arr[n] = arr[i];
            arr[i] = key;
        }

    }
    CLockEnd();
/////////////////

    for(auto i : arr)
        std::cout << i << " "  ;
    std::cout << std::endl;

}

void buble()
{
    srand(time(NULL));

    std::array<int, 10> arr;

    for(auto i = 0; i < arr.size(); i++)
        arr[i] = rand() % 100 + 1;


    for(auto i : arr)
        std::cout << i << " " ;
    std::cout << std::endl;


    int key;
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr.size()-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                key = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = key;
            }
        }

    }

    for(auto i : arr)
        std::cout << i << " " ;
    std::cout << std::endl;

}

void MergeSort( int arr[] , int left,int k, int right)
{
    std::cout << left << " " << k << " " << right << std::endl;

    int i,j,m=0;
    int temp[19];

    for(i = left, j = k+1; (i <= k) && (j <= right); )
    {
        if(arr[i] < arr[j])
        {
            temp[m]= arr[i];


     .       i++;
            m++;
        }

        else
        {
            temp[m]= arr[j];
            j++;
            m++;
        }

    }

    while(i <= k)
    {
        temp[m] = arr[i];
        i++;
        m++;
    }

    while (j <= right){
        temp[m] = arr[j];
        j++;
        m++;
    }

    for(auto n : temp)
        std::cout << n << " " ;
    std::cout << std::endl;


    for(i = left, m = 0; i <= right; i++, m++)
    {
        arr[i] = temp[m];
    }


}
void Merge( int arr[], int l, int r)
{
    if(l < r)
    {
        int mid = ( r + l ) / 2;
     //   std::cout << l << " " << mid << " " << r << std::endl;
        Merge(arr, l, mid);
        Merge(arr, mid + 1, r);
        MergeSort(arr, l, mid, r);

    }

}


void QuickSort(int arr[], int l, int r)
{
    int i = l , j = r;
    int p = arr[(i + j) / 2];

    while( i <= j)
    {
        while(arr[j] > p && j > l)
        {
            j--;
        }

        while(arr[i] < p && i < r)
        {
            i++;
        }

        if(i <= j)
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j--;
            i++;
        }

    }
    std::cout << "index " << i << " " << j << std::endl;
    std::cout << "values " <<  arr[i] << " " << arr[j] << std::endl;
    if(l < j)
        QuickSort(arr,l,j);
    if(i < r)
        QuickSort(arr,i,r);


/*
    int j = r-1,i=l,p=0;
    p = arr[r];

    std::cout << arr[i] << " " << arr[j] << " " << p << std::endl;

    while(i < j)
    {
        while(arr[i] <= p && i < r)
        {
            i++;
        }

        while(arr[j] >= p && j > l)
        {
            j--;
        }

        arr[i] ^= arr[j];
        arr[j] ^= arr[i];
        arr[i] ^= arr[j];
        i++;
        j--;
    }

    if( i > j)
    {
        arr[i] ^= arr[r];
        arr[r] ^= arr[i];
        arr[i] ^= arr[r];
    }

    std::cout << "index " << i << " " << j << std::endl;

    for(int k = 0; k < 8 ; k++)
        std::cout << arr[k] << " ";
    std::cout << "\n" ;

    if(i < r)
        QuickSort(arr,i+1,r);
*/

}

void Heapify(int arr[], int S , int P)
{
    int b = P;
    int l = 2 * P + 1;
    int r = 2 * P + 2;

    if( l < S && arr[l] > arr[b])
        b = l;
    if( r < S && arr[r] > arr[b])
        b = r;

    if(b != P)
    {
        int temp = arr[P];
        arr[P] = arr[b];
        arr[b] = temp;

        Heapify(arr, S, b);
    }


}
void Heap(int arr[], int S)
{
    for(int i = 2 * S - 1 ; i >= 0; i--)
       Heapify(arr,S,i);

    for(int i = S - 1 ; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        Heapify(arr, i, 0);

    }

}

int main()
{

    srand(time(NULL));

    int arr[19];
    int size = sizeof(arr) / sizeof(arr[0]);


    for(auto i = 0; i < size; i++)
        arr[i] = rand() % 10000 + 1;

    for(auto i : arr)
        std::cout << i << " " ;
    std::cout << std::endl;

    //Heap(arr, size);
    Merge(arr, 0, size-1);

    for(auto i : arr)
        std::cout << i << " " ;
    std::cout << std::endl;


    return 0;

}