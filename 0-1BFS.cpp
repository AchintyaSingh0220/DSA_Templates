#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define pb push_back
#define pii pair<ll, ll>
#define vii vector<pii>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define vvi vector<vi>
#define mii map<ll, ll>
#define umii unordered_map<ll, ll>
#define F first
#define S second

#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rrep(i, a, b) for (ll i = b - 1; i >= a; i--)
#define calc_fact(n) tgamma(n + 1)

#define endl "\n"
#define print(v)           \
    for (auto &it : v)     \
        cout << it << " "; \
    cout << endl;
#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define deb(x) cout << #x << "=" << x << endl
#define in(a) \
    ll int a; \
    cin >> a
#define inn(a, b) \
    ll int a, b;  \
    cin >> a >> b
#define innn(a, b, c) \
    ll int a, b, c;   \
    cin >> a >> b >> c
#define out(a) cout << a << endl
#define outt(a, b) cout << a << " " << b << endl

#define MOD 998244353
#define gcd(a, b) __gcd(a, b)

const int N = 1e5 + 10;
ll n, m;
vector<pair<int, int>> adj[N];
vi cost(N, 1e9);

ll bfs(ll vertex, vector<pair<int, int>> adj[])
{
    deque<ll> q;
    q.pb(1);
    cost[1] = 0;

    while (!q.empty())
    {
        ll curr_vertex = q.front();
        q.pop_front();

        for (auto child : adj[curr_vertex])
        {
            ll curr_child = child.first;
            ll wt = child.second;

            if ((cost[curr_vertex] + wt) < cost[curr_child])
            {
                cost[curr_child] = cost[curr_vertex] + wt;
                if (wt == 1)
                {
                    q.pb(curr_child);
                }
                else
                    q.push_front(curr_child);
            }
        }
    }

    return cost[n] == 1e9 ? -1 : cost[n];
}

void solution()
{
    cin >> n >> m;

    rep(i, 0, m)
    {
        ll u, v;
        cin >> u >> v;

        adj[u].pb({v, 0});
        adj[v].pb({u, 1});
    }

    ll res = bfs(1, adj);
    out(res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;
    // cin >> t;
    // rep(i, 1, t + 1)
    // {
    //     // cout << "Case #" << i << ": ";
    //     solution();
    // }

    solution();

    return 0;
}
