#include <bits/stdc++.h>
using namespace std;

vector<int>  g[100005];
int in[100005], low[100005];
int vis[100005];
int timer;

void dfs(int u, int par = -1)
{
    vis[u] = 1;
    in[u] = low[u] = timer++;

    for(auto v : g[u])
    {
        if(v == par) continue;

        if(vis[v])
        {
            //back edge
            low[u] = min(low[u], in[v]);
        }
        else
        {
            //forward edge
            dfs(v, u);

            low[u] = min(low[u], low[v]);
            if(low[v] > in[u]) cout<<u<<' '<<v<<" is a bridge"<<endl;
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
        g[v].push_back(u);
    }

    dfs(1);
}