#include <bits/stdc++.h>
using namespace std;
#define N 6

vector<int> vec[N];
stack<int> st;
int visited[N] = {0};

void dfs(int i)
{
    visited[i] = true;

    for (auto & j : vec[i])
        if(!visited[j])
            dfs(j);
    st.push(i);

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


    for (int i = 0; i < N; ++i)
        if(!visited[i])
            dfs(i);

    // print
    while(!st.empty())
    {
        cout << st.top() + 1 << " " ;
        st.pop();
    }




}