#include <iostream>
#include <chrono>
#include <array>
#include <time.h>

auto s = std::chrono::system_clock::now();
auto f = std::chrono::system_clock::now();

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


int main()
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

    }

    for(auto i : arr)
        std::cout << i << " " ;
    std::cout << std::endl;





    return 0;

}