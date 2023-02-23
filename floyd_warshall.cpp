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

const int inf = 1e9 + 10;
const int N = 510;
int dist[N][N];

void solution()
{
    in(n);
    in(m);

    rep(i, 0, n + 1)
    {
        rep(j, 0, n + 1)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = inf;
        }
    }

    rep(i, 0, m)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        dist[u][v] = wt;
    }

    rep(k, 1, n + 1)
    {
        rep(i, 1, n + 1)
        {
            rep(j, 1, n + 1)
            {
                if (dist[i][k] != inf && dist[k][j] != inf)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    rep(i, 1, n + 1)
    {
        rep(j, 1, n + 1)
        {
            if (dist[i][j] == inf)
                cout << "I ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
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
