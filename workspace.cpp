#include <bits/stdc++.h>
using namespace std;

vector<int> g[100005];
int in[100005];
vector<int> res;

void bfs(int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 1; i<=n; i++)
    {
        if(in[i] == 0) pq.push(i);
    }

    while(!pq.empty())
    {
        int u = pq.top();
        pq.pop();
        res.push_back(u);

        for(auto v : g[u])
        {
            in[v]--;
            if(in[v] == 0) pq.push(v);
        }
    }
}

int main()
{
    int n, m;
    cin>>n>>m;

    for(int i = 0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;

        g[u].push_back(v);
        in[v]++;
    }

    bfs(n);

    if(res.size() != n) cout<<"Sandro fails."<<endl;
    else {
        for(int i = 0; i<res.size(); i++) cout<<res[i]<<' '; cout<<endl;
    }

    return 0;
}