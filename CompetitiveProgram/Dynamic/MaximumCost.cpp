#include <bits/stdc++.h>
using namespace std;

int value[5][5] = {
            {3,7,9,2,7},
            {9,8,3,5,5},
            {1,7,9,8,5},
            {3,8,6,4,10},
            {6,3,9,7,8}
                };

void findPath()
{

    int n = 5;
    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < n; ++j) {
            if (j >= 1 && i >= 1) {
                value[i][j] += max(value[i - 1][j], value[i][j - 1]);
            } else if (i == 0 && j == 0)
                continue;

            if (i == 0)
                value[i][j] += value[i][j - 1];
            if (j == 0) value[i][j] += value[i - 1][j];

        }
    }

    for (auto & i : value) {
        for (auto & j : i ) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{


//    findPath();
}


