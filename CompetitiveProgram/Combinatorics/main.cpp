#include <bits/stdc++.h>
using namespace std;

int FindNumberBinomialCoefficient(int n, int k)
{

    if (k == 0 || k == n)
        return 1;

    return FindNumberBinomialCoefficient(n - 1, k - 1)
           + FindNumberBinomialCoefficient(n - 1, k);
}

int Combinatorics(int sum, int largestNumber){

    if (largestNumber==0)
        return 0;

    if (sum==0)
        return 1;

    if (sum<0)
        return 0;

    return Combinatorics(sum,largestNumber-1)
           + Combinatorics(sum-largestNumber,largestNumber);
}

/// on process
void BinomialCoefficient(int m, int n)
{
/*
    int c,v;

    for (int i = 0; i < m-n+1; ++i) {
        cout << i+1 << " ";
        for (int j = i+1; j < m - 1; ++j) {
            cout << j + 1 << " " <<  << endl;
        }

    }
*/

}

void Pascal(int n)
{
    int arr[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == j || j == 0) arr[i][j] = 1;
            else  arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];

            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

}




int main(){
    int n = 5;
    Pascal(n);
//    BinomialCoefficient(5,3);

//    cout << FindNumberBinomialCoefficient(5,3) << endl;

//    int sum = 4;
//    cout << Combinatorics(sum,sum-1) << endl;

    return 0;
}