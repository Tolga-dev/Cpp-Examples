#include <bits/stdc++.h>
using namespace std;
#define N 5

// WILL BE UPDATED

void BellmanFord(int distance[N], vector<tuple<int,int,int>> adj[N], int visited[N], int s )
{
    distance[s] = 0;

    for (int i = 0; i < N-1; ++i) {
        for (auto & j : adj[N]) {
            int a, b, w;
            tie(a, b, w) = j;
            distance[b] = min(distance[b], distance[a]+w);
        }
    }
}


int main()
{


    vector<tuple<int,int,int>>  adj[N];
    int distance[N] = {0},processed[N] = {0}, s = 0;

    for (auto & i : distance) i = INFINITY;

    adj[0].emplace_back(0,2, 3);
    adj[0].emplace_back(0,3, 7);
    adj[0].emplace_back(0,1, 5);

    adj[1].emplace_back(1,3, 3);
    adj[1].emplace_back(1,0,5);
    adj[1].emplace_back(1,4,2);

    adj[2].emplace_back(2,0,3);
    adj[2].emplace_back(2,3,1);

    adj[3].emplace_back(3,0,7);
    adj[3].emplace_back(3,1,3);
    adj[3].emplace_back(3,4,2);

    adj[4].emplace_back(4,1,2);
    adj[4].emplace_back(4,3,2);

    BellmanFord(distance,adj,processed,s);

    for(auto & i : distance)
    {
        cout << i << endl;
    }

}
