#include <iostream>
using namespace std;
#define GetSize(ar) (sizeof(ar) / sizeof((ar)[0]))
#define Print(arr) for(auto & i : (arr)){ std::cout << i  << endl;}

void FindNearestSmallerNumber(int arr[], int n)
{
    cout << "0 " << arr[0] << endl;

    for (int i = 0; i < n; i++) {
        for (int j = i-1; j >= 0; j--) {
            if (arr[j] < arr[i]) {
                cout << arr[j] << " " << arr[i] << endl;
                break;
            }
        }

    }
}

int main()
{
    int arr[] = {0, 1, 6, 4, 10, 2, 5};
    FindNearestSmallerNumber(arr,GetSize(arr));


}

