#include <bits/stdc++.h>
#include <limits>
#define INF 999999

using namespace std;

int coins[] = {1,3,4};

int min(int x, int y)
{
    return x < y ? x : y;
}
int solve(int x) {
    if (x < 0) return INF;
    if (x == 0) return 0;
    int best = INF;
    for (auto c : coins) {
        best = min(best, solve(x-c)+1);
    }
    return best;

}

int main()
{

    cout << solve(10) << endl;

}


