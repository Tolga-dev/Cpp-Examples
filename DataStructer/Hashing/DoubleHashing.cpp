#include <bits/stdc++.h>
#include <iostream>
using namespace std;


void hashing(int table[], int size, int arr[], int N)
{
    auto index = [&](int i)
    {
        int PRIME = 7; // prime is a prime number smaller than size

        int hv = arr[i] % size;
        int hv2 = PRIME - (arr[i] % PRIME);

        return (hv + i*hv2)%size;
    };

    for (int i = 0; i < N; i++) {

        int hv = index(i);
        int j = i;
        if (table[hv] == -1)
            table[hv] = arr[i];
        else {
            while(true)
            {
                int t = index(j);
                if (table[t] == -1) {

                    table[t] = arr[i];
                    break;
                }
                j++;
            }
        }
    }
}
void out(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << i << " " << arr[i] << std::endl;
    }
}

int main()
{
    int N = 10;

    int arr[] = { 11,11,11,2,3,5,5,5};

    int hash_table[N];

    for (int i = 0; i < N; i++) {
        hash_table[i] = -1;
    }

    hashing(hash_table, N, arr, N);
    out(hash_table, N);


    return 0;
}