#include <bits/stdc++.h>
using namespace std;

#define N 5

void Dfs(vector<int> adj[N],bool visited[N],int s)
{
    if(visited[s])
        return;

    cout << s << endl;
    visited[s] = true;

    for (auto & i : adj[s]) {
        Dfs(adj,visited,i);
    }
}


int main()
{
    vector<int> adj[N];
    bool visited[N] = {false};

    adj[0].push_back(3);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(4);
    adj[4].push_back(1);


    Dfs(adj,visited,0);

}
