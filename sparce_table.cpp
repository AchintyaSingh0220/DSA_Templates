#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX_N = 100'005;
const int LOG = 25;
ll a[MAX_N];
ll m[MAX_N][LOG]; // m[i][j] is minimum among a[i..i+2^j-1]
ll bin_log[MAX_N];

// can be used for min, max and gcd
ll query(ll L, ll R)
{ // O(1)
    ll length = R - L + 1;
    ll k = bin_log[length];
    return min(m[L][k], m[R - (1 << k) + 1][k]);
}

// n : length of input array
void build(ll n)
{
    bin_log[1] = 0;
    for (ll i = 2; i <= n; i++)
    {
        bin_log[i] = bin_log[i / 2] + 1;
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        m[i][0] = a[i];
    }
    // 2) preprocessing, O(N*log(N))
    for (ll k = 1; k < LOG; k++)
    {
        for (ll i = 0; i + (1 << k) - 1 < n; i++)
        {
            m[i][k] = min(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
        }
    }
}

int main()
{
    ll n;
    cin >> n;

    build(n);

    int q;
    cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }

    return 0;
}