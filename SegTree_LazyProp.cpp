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
#define ff first
#define ss second

#define mem(a, val) memset(a, val, sizeof(a))
#define each(x, a) for (auto &x : a)
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (b) - 1; i >= (a); i--)
#define each(x, a) for (auto &x : a)
#define calc_fact(n) tgamma(n + 1)
#define amax(a, k) a = max(a, k)
#define amin(a, k) a = min(a, k)

#define endl "\n"
#define print(v)           \
    for (auto &it : v)     \
        cout << it << " "; \
    cout << endl;
#define read(a, n) \
    vi a(n);       \
    rep(i, 0, n) cin >> a[i]
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
#define ps(x, y) fixed << setprecision(y) << x

#ifndef ONLINE_JUDGE
#define deb(...)                       \
    logger(#__VA_ARGS__, __VA_ARGS__); \
    cout << endl
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
}
#else
#define deb(...) 0
#endif

#define gcd(a, b) __gcd(a, b)

inline namespace handyFunctions
{
    int popcount(ll x) { return __builtin_popcountll(x); };
    ll ceil(ll n, ll div)
    {
        assert(div > 0);
        return n >= 0 ? (n + div - 1) / div : n / div;
    }
    ll floor(ll n, ll div)
    {
        assert(div > 0);
        return n >= 0 ? n / div : (n - div + 1) / div;
    }
    ll digitsum(ll n)
    {
        ll ret = 0;
        while (n)
        {
            ret += n % 10;
            n /= 10;
        }
        return ret;
    }
    void ynans(bool x)
    {
        if (x)
            out("Yes");
        else
            out("No");
    }
    bool is2pow(ll n) { return !(n & (n - 1)); }

    template <typename T>
    T min(const vector<T> &v) { return *min_element(v.begin(), v.end()); }
    template <typename T>
    T max(const vector<T> &v) { return *max_element(v.begin(), v.end()); }
    template <typename T>
    T acc(const vector<T> &v) { return accumulate(v.begin(), v.end(), T(0)); };
    template <typename T>
    T reverse(const T &v) { return T(v.rbegin(), v.rend()); };
    int sum() { return 0; }
    template <typename T, typename... Args>
    T sum(T a, Args... args) { return a + sum(args...); }
    ll _min() { return 1e18; }
    template <typename T, typename... Args>
    T _min(T a, Args... args) { return std::min(a, T(_min(args...))); }
    ll _max() { return -1e18; }
    template <typename T, typename... Args>
    T _max(T a, Args... args) { return std::max(a, T(_max(args...))); }
}

inline namespace FileIO
{
    void setIn(string s) { freopen(s.c_str(), "r", stdin); }
    void setOut(string s) { freopen(s.c_str(), "w", stdout); }
    void setIO(string s = "")
    {
        ios::sync_with_stdio(false);
        cin.tie(0);

        if (!s.empty())
            setIn(s + ".in"), setOut(s + ".out");
    }
}

const ll inf = 1e9;
const ll linf = 1e18;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

long long add(long long a, long long b){
    return (MOD + a % MOD + b % MOD) % MOD;
}

long long mult(long long a, long long b){
    return (a % MOD * b % MOD) % MOD;
}

unsigned long long power(unsigned long long a, int b)
{
    unsigned long long res = 1;
    a = a % MOD;
    while (b > 0) 
    {
        if (b & 1) res = (res * a) % MOD;
        b = b >> 1; 
        a = (a * a) % MOD;
    }
    return res;
}

unsigned long long inv(unsigned long long a)
{
    return power(a, MOD - 2);
}

long long fact[N], invfact[N];
void init()
{
    int p = MOD;
    fact[0] = 1;
    int i;
    for(i = 1; i<N; i++){
        fact[i] = i*fact[i-1]%p;
    }
    i--;
    invfact[i] = inv(fact[i]);
    for(i--; i>=0; i--){
        invfact[i] = invfact[i+1]*(i+1)%MOD;
    }
}

unsigned long long fast_comb(unsigned long long n, int r)
{
    if (n < r || n < 0 || r < 0) return 0;
    return mult(fact[n], mult(invfact[n-r], invfact[r]));
}

struct d{
    long long sum, lz=0;
};
vector<d> tree;
void build(vector<int> &arr, int &n)
{
    while(__builtin_popcount(n) != 1) n++;
    tree.resize(2 * n);
    for(int i = 0; i<arr.size(); i++){
        tree[n + i].sum = arr[i];
    }
    for(int i = n-1; i>=1; i--){
        tree[i].sum = tree[2 * i].sum + tree[2 * i + 1].sum;
    }
}
void appl(int node, int tl, int tr, long long val)
{
    tree[node].sum += (tr - tl + 1) * val;
    tree[node].lz += val;
}
void push(int node, int tl, int tmid, int tr)
{
    appl(2 * node, tl, tmid, tree[node].lz);
    appl(2 * node + 1, tmid + 1, tr, tree[node].lz);

    tree[node].lz = 0;
}
//default values: node->1, tl->0, tr->n-1
//increament range [l, r] by val
void update(int node, int tl, int tr, int l, int r, int val)
{
    if(l > tr || tl > r) return;
    if(l <= tl && tr <= r){
        appl(node, tl, tr, val);
        return;
    }

    int mid = (tl + tr) / 2;
    push(node, tl, mid, tr);
    update(2* node, tl, mid, l, r, val);
    update(2 * node + 1, mid + 1, tr, l, r, val);
    tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
}
//qry for sum in range [l,r]
long long qry(int node, int tl, int tr, int l, int r)
{
    if(l > tr || tl > r) return 0; //here 0 is identity element
    if(l <= tl && tr <= r) return tree[node].sum;

    int mid = (tl + tr) / 2;
    push(node, tl, mid, tr);
    return qry(2 * node, tl, mid, l, r) + qry(2 * node + 1, mid + 1, tr, l, r);
}

void solution()
{
    int n, q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];
    build(arr, n);
    for(int i = 0; i<q; i++)
    {
        int op;cin>>op;
        if(op == 1)
        {
            int l, r, val;cin>>l>>r>>val, l--, r--;
            update(1, 0, n-1, l, r, val);
        } else {
            int l, r; cin>>l>>r, l--,r--;
            cout<<qry(1, 0, n-1, l, r)<<endl;
        }
    }
}

int main()
{
    setIO();
    int t = 1;
    // cin >> t;
    rep(i, 1, t + 1)
    {
        // cout << "Case #" << i << ": ";
        solution();
    }

    return 0;
}
