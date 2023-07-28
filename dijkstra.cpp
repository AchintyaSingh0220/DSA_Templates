#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> g[100005];
int dist[100005];
const int inf = 1e9;

void bfs(int node)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, node));
    dist[node] = 0;

    while(!pq.empty())
    {
        auto [w, u] = pq.top();
        pq.pop();

        if(w > dist[u]) continue;
        
        for(auto it : g[u])
        {
            auto [v, w2] = it;
            if(w2 + w < dist[v]){
                dist[v] = w2 + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main()
{
    int n, m;
    cin>>n>>m;

    for(int i = 0; i<m; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    for(int i = 1; i<=n; i++) dist[i] = inf;
    bfs(1);

    for(int i = 1; i<=n; i++) cout<<dist[i]<<' '; cout<<endl;

    return 0;
}