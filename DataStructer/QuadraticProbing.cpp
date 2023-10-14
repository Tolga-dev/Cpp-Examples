#include <bits/stdc++.h>
using namespace std;


void hashing(int table[], int size, int arr[], int N)
{
    for (int i = 0; i < N; i++) {
        int hv = arr[i] % size;
        int j = 1;
        if (table[hv] == -1)
            table[hv] = arr[i];
        else {
                while(true)
                {
                    int t = (hv + j * j) % size;
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