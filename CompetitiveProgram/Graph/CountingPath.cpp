#include <bits/stdc++.h>
using namespace std;
#define N 6

vector<int> vec[N];
int visited[N] = {0};
int countPath[N] = {0};


void CountingPaths(int i)
{
    visited[i] = true;
    countPath[i] += 1;

    for (auto & j : vec[i])
    {
        if(!visited[j])
        {
            CountingPaths(j);
        }

    }

    visited[i] = false;
}

int main()
{


    vec[0].emplace_back(1);
    vec[0].emplace_back(3);
    vec[1].emplace_back(2);
    vec[2].emplace_back(5);
    vec[3].emplace_back(4);
    vec[4].emplace_back(1);
    vec[4].emplace_back(2);


    CountingPaths(0);

    for (auto & i: countPath) {
        cout << i << " ";
    }



}