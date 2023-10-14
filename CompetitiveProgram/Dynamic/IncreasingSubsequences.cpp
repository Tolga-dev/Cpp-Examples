#include <bits/stdc++.h>
#define size(arr) sizeof(arr) / sizeof(arr[0])


int array[] = {6,2,5,1,7,4,8,3};

int max(int i,int j)
{
    return i > j ? i : j;
}
void Find()
{
    int n = size(array);
    int length[size(array)] = {0};

    for (int i = 0; i < n; ++i) {
        length[i] = 1;
        for (int j = i-1; 0 <= j; --j) {
            if(array[j] < array[i])
            {
                length[i] = max(length[i],length[j]+1);
            }
        }
    }

    for (auto & i : length) {
        std::cout << i << std::endl;
    }

}

int main()
{
    Find();
}

