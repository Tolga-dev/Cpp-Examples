#include <iostream>
using namespace std;
#define GetSize(ar) (sizeof(ar) / sizeof((ar)[0]))
#define Print(arr) for(auto & i : (arr)){ std::cout << i  << endl;}

void SlidingWindowMinimum(int arr[], int n)
{
    int min = 0;
    for (int i = 0; i <= n-4; ++i) {
        min = arr[i];
        for (int j = i; j < i+4; ++j) {
            if(min > arr[j])
                min = arr[j];
            cout << arr[j] << " ";
        }
        cout << " <- "<<  min << endl;

    }

}

int main()
{
    int arr[] = {2,2,2,4,4,4,4,5,5,5,5,1};

    SlidingWindowMinimum(arr,GetSize(arr));


}

