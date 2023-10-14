#include <iostream>
using namespace std;
#define GetSize(ar) (sizeof(ar) / sizeof((ar)[0]))
#define Print(arr) for(auto & i : (arr)){ std::cout << i  << endl;}

int Find(int arr[], int n, int a, int b)
{
    if(a == b)
    {
        return arr[a];
    }
    else if(abs(a-b) == 1)
    {
        return min(arr[a],arr[b]);
    }

   return min( min(a, a + ((b-a+1) / 2) -1) , min(a+((b-a+1)/2),b) );
}

int main()
{
    int arr[] = {1,3,4,8,6,1,4,2};
    int begin = 1, end = 2;
    cout << Find(arr,GetSize(arr),begin,end) << endl;


}

