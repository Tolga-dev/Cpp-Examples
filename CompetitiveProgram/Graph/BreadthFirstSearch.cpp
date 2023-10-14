#include <bits/stdc++.h>
using namespace std;

#define N 5

void Bfs(vector<int> adj[N],queue<int> sub, bool visited[N],int distance[N],int s)
{
    visited[s] = true;
    distance[s] = 0;
    sub.push(s);

    while(!sub.empty())
    {
        int x = sub.front();

        sub.pop();

        for (auto & u : adj[x]) {
            if(visited[u]) continue;
            visited[u] = true;
            distance[u] = distance[x] + 1;
            sub.push(u);
        }
    }

}


int main()
{
    vector<int> adj[N];
    bool visited[N] = {false};
    int distance[N] = {0};
    queue<int> sub;

    adj[0].push_back(3);
    adj[1].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(1);
    adj[3].push_back(1);
    adj[4].push_back(2);


    Bfs(adj,sub,visited,distance,0);

    for (auto & i: distance) {
        cout << i << endl;
    }
}
