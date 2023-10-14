#include <bits/stdc++.h>
using namespace std;
#define N 6


void DijkstraCountingPaths(vector<pair<int,int>> vec[N],
                            int distance[N],
                            int processed[N],
                            priority_queue<pair<int,int>> q,
                            int s,
                            int paths[N]

)
{
    processed[s] = true;

    for (auto & i : vec[s]) {
        int b = i.first, w = i.second;

        if(distance[s] + w <= distance[b])
        {
            paths[b] += 1;
            distance[b] = distance[s] + w;

            DijkstraCountingPaths(vec,distance,processed,q,b,paths);
        }
    }
    processed[s] = false;


}

int main()
{
    vector<pair<int,int>> vec[N];
    int distance[N] = {0}, processed[N] = {0};
    priority_queue<pair<int,int>> q;
    int paths[N] = {0};

    for(auto & i : distance) i = 999999;

    paths[0] = 1;
    distance[0] = 0;

    vec[0].emplace_back(1,3);
    vec[0].emplace_back(2,5);
    vec[1].emplace_back(2,2);
    vec[1].emplace_back(3,4);
    vec[1].emplace_back(4,8);
    vec[2].emplace_back(3,2);
    vec[3].emplace_back(4,1);

    DijkstraCountingPaths(vec,distance,processed,q,0,paths);

    for (int i = 0; i < N; ++i) {
        cout << paths[i] << " ";
    }

}