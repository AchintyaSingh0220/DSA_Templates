#include <bits/stdc++.h>
using namespace std;

vector<int> g[100005];
vector<int> g_rev[100005];
vector<int> order, SCC;
int roots[100005];
vector<int> root_list;
int vis[100005];
vector<int> adj_scc[100005];

void dfs1(int u)
{
    vis[u] = 1;

    for(auto v : g[u])
    {
        if(!vis[v]) dfs1(v);
    }

    order.push_back(u);
}

void dfs2(int u)
{
    vis[u] = 1;
    SCC.push_back(u);

    for(auto v : g_rev[u])
    {
        if(!vis[v]) dfs2(v);
    }
}

int main()
{
    int n, m;
    cin>>n>>m;

    for(int i =0 ; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g_rev[v].push_back(u);
    }

    for(int i = 1; i<=n; i++)
    {
        if(!vis[i]) dfs1(i);
    }

    reverse(order.begin(), order.end());
    memset(vis, 0, sizeof vis);

    for(auto u : order)
    {
        if(!vis[u]){
            dfs2(u);

            int root = SCC.front();
            for(auto it : SCC) roots[it] = root;
            root_list.push_back(root);

            SCC.clear();
        }
    }

    for(int u = 1; u<=n; u++)
    {
        for(auto v : g[u]){
            int root_v = roots[v];
            int root_u = roots[u];

            if(root_u != root_v) adj_scc[root_u].push_back(root_v);
        }
    }
    return 0;
}