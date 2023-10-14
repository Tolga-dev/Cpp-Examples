#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    map<int,bool> visited;
    map<int, list<int>> adj;

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }
    void dfs(int v)
    {
        visited[v] = true;

        for(auto i = adj[v].begin(); i != adj[v].end(); i++)
        {

            if(!visited[*i])
            {
                cout << *i << " ";

                dfs(*i);
            }
        }
    }

};


int main() {

    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(3, 3);
    g.addEdge(4, 4);

    // Function call
    g.dfs(0);
}
