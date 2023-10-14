#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void dfs(int v, map<int,list<int>> adj ,int visited[])
{
    std::cout << v<< std::endl;

    visited[v] = true;

    for(int & i : adj[v])
    {
        if(!visited[i])
            dfs(i,adj,visited);
    }
}

int main()
{
    map<int,list<int>> adj;
    int arr[10][2] = {
              {0,2},{0,3},{0,1},
              {1,0},{1,2},{1,4},
              {2,1},{2,0},
              {3,0},
              {4,1}
        };

    for (auto & i : arr) {
        adj[i[0]].push_back(i[1]);
    }

    int visited[5] = {0,0,0,0,0};

    dfs(0,adj,visited);

    return 0;
}