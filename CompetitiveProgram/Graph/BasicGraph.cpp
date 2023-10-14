#include <bits/stdc++.h>
using namespace std;

#define N 4


int main()
{
    // undirected
    vector<pair<int, int>> adj[N];
    adj[1].emplace_back(1,4);
    adj[1].emplace_back(1,5);
    adj[2].emplace_back(2,4);
    adj[2].emplace_back(2,5);

    for (auto & i : adj) {
        for (auto & j : i) {
            cout << j.first << " -> " << j.second << " ";
        }
        cout << endl;
    }
    // directed
    {
        vector<int> adj[N];
        adj[1].push_back(2);
        adj[2].push_back(3);
        adj[2].push_back(4);
        adj[3].push_back(4);
        adj[4].push_back(1);

        for (auto &i: adj) {
            for (int j: i) {
                cout << j << " -> ";
            }
            cout << endl;
        }

    }





}
