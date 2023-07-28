#include <bits/stdc++.h>
using namespace std;

//Kahn's algorithm
//works for Directed Acylclic Graph (DAG)

vector<int> g[100005];
int in[100005];
vector<int> res;

void topoSort(int n)
{
    queue<int> q;
    for(int i = 1; i<=n; i++)
    {
        if(in[i] == 0) q.push(i);
    }

    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        res.push_back(t);

        for(auto v : g[t])
        {
            in[v]--;
            if(in[v] == 0) q.push(v);
        }
    }

    for(auto val : res)
    {
        cout<<val<<' ';
    }
    cout<<endl;
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

    topoSort(n);

    return 0;
}