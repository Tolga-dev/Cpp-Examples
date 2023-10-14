#include <bits/stdc++.h>
using namespace std;
#define N 5

void Dijkstra(priority_queue<pair<int,int>> q, int distance[N], vector<pair<int,int>> adj[N],int processed[N], int s)
{
    distance[s] = 0;
    q.push({0,s});
    while(!q.empty())
    {
        int a = q.top().second; q.pop();
        if(processed[a]) continue;

        processed[a] = true;

        for(auto & i : adj[a])
        {
            int b = i.first, w = i.second;
            if(distance[a] + w < distance[b])
            {
                distance[b] = distance[a] + w;
                q.push({-distance[b],b});
            }
        }
    }

}


int main()
{
    vector<pair<int,int>>  adj[N];
    int distance[N] = {0},processed[N] = {0}, s = 0;
    priority_queue<pair<int,int>> q;

    for (auto & i : distance) i = INFINITY;

    adj[0].emplace_back(4, 1);
    adj[0].emplace_back(3, 9);
    adj[0].emplace_back(1, 5);

    adj[1].emplace_back(2, 2);
    adj[1].emplace_back(0,5);

    adj[2].emplace_back(1,2);
    adj[2].emplace_back(3,6);

    adj[3].emplace_back(0,9);
    adj[3].emplace_back(2,6);
    adj[3].emplace_back(4,2);

    adj[4].emplace_back(0,1);
    adj[4].emplace_back(3,2);


    Dijkstra(q,distance,adj,processed,s);

    for(auto & i : distance)
    {
        cout << i << endl;
    }

}
