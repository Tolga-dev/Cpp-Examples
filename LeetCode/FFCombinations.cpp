#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/combinations/solutions/3007002/c-solution-backtracking/?languageTags=cpp

//std::fill(v.end() - r, v.end(), true);
/*
 *     for (int i = 1; i < n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            coms.push_back(vector<int>{i,j});
        }
    }
*/

vector<vector<int>> coms;

/*vector<vector<int>> combine(int n, int k) {

    for (int i = 0; i < n-k+1; ++i) {
        cout << i+1 << endl;
    }


    return coms;
}*/

void combinationUtil(int arr[], int data[],
                     int start, int end,
                     int index, int r);

void printCombination(int arr[], int n, int r)
{
    int data[r];

    combinationUtil(arr, data, 0, n-1, 0, r);
}

void combinationUtil(int arr[], int data[],
                     int start, int end,
                     int index, int r)
{
    if (index == r)
    {
        for (int j = 0; j < r; j++)
            cout << data[j] << " ";
        cout << endl;
        return;
    }

    for (int i = start; i <= end &&
                        end - i + 1 >= r - index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1,
                        end, index+1, r);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int r = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    printCombination(arr, n, r);
}