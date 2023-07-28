#include <bits/stdc++.h>
using namespace std;

vector<int> g[100005];
int col[100005];
int vis[100005];

bool dfs(int u, int c)
{
    vis[u] = 1;
    col[u] = c;

    for(int v : g[u])
    {
        if(vis[v])
        {
            if(col[v] == col[u]) return false;
        }
        else{
            if(dfs(v, c ^ 1) == false) return false;
        }
    }

    return true;
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

    if(dfs(1, 0)){
        cout<<"YES"<<endl;
    } else cout<<"NO"<<endl;

    for(int i = 1; i<=n; i++)
    {
        cout<<col[i]<<' ';
    } cout<<endl;

    return 0;
}