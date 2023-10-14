#include <iostream>
using namespace std;

// pes ettim

#define GetSize(ar) (sizeof(ar) / sizeof((ar)[0]))
#define Print(arr) for(auto & i : (arr)){ std::cout << i  << endl;}

void GetTree(int arr[], int tree[], int size, int j)
{
   int c = 0;
    for (int i = j, k = j; i < size; i++,k+=2) {
        tree[i] = arr[i];

        if(k < size)
        {
            tree[i+size] = arr[k] + arr[k+1];
            c++;
        }
    }

    for (int i = 0; i < 15; ++i) {
        cout << tree[i] << " ";
    }
    cout << endl;

}

void Find(int arr[], int n)
{


}

int main()
{

    int arr[] = {5,8,6,3,2,7,2,6};
    int treeArr[15] = {0};
    int sizeArr = GetSize(arr);
//    Find(arr,GetSize(arr));
    GetTree(arr,treeArr,8,0);


}

