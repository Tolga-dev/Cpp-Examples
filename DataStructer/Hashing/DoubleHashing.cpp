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
    int arr[] = { 50, 700, 76, 85, 92, 73, 101,123,120,11};

    int hash_table[10];

    for (int i = 0; i < 10; i++) {
        hash_table[i] = -1;
    }

    hashing(hash_table, 10, arr, 10);
    out(hash_table, 10);


    return 0;
}