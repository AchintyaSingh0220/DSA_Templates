#include <bits/stdc++.h>
using namespace std;

// O(alpha(n));
// where alpha is reverse ackermann function
// amortized time complexity
const int N = 1e5 + 10;

int parent[N];
int sz[N];

void make(int u)
{
    parent[u] = u;
    sz[u] = 1;
}

int find(int u)
{
    // if(parent[u] == -1)
    // {
    //     parent[u] = u;
    //     return u;
    // }
    if (parent[u] == u)
        return u;
    // Path compression
    return parent[u] = find(parent[u]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        // Union by size
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    while (k--)
    {
        int u, v;
        cin >> u >> v;

        Union(u, v);
    }

    int connected_cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        if (find(i) == i)
        {
            connected_cnt++;
        }
    }

    cout << connected_cnt;
    return 0;
}