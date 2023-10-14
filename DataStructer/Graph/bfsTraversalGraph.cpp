#include <iostream>
#include <bits/stdc++.h>

using namespace std;


void bfs(int v, map<int,list<int>> adj ,int visited[])
{
    visited[v] = true;
    list<int> q;

    q.push_back(v);

    while(!q.empty())
    {
        v = q.front();
        std::cout << v << std::endl;
        q.pop_front();

        for (auto i : adj[v] ) {
            if(!visited[i])
            {
                visited[i] = true;
                q.push_back(i);
            }
        }

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
    bfs(0,adj,visited);

    return 0;
}