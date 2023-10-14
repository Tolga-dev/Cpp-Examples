#include <iostream>
using namespace std;

int binary(int D[], int l, int r, int key)
{
    if(r >= l)
    {
        int mid = l + (r - l ) / 2;

        if(D[mid] == key)
            return mid;

        if(D[mid] > key)
            return binary(D,l,mid - 1,key);
        return binary(D,mid + 1,r, key);
    }
    return 0;
}

int main()
{

    int D[10] = {1,2,3,4,5,6,7,8,9,10};

    std::cout << binary(D,0,9,8) << std::endl;

}

