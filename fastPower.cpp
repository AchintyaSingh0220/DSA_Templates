#include <iostream>
using namespace std;

int fastPower(int a, int b, int MOD)
{
    int res = 1;

    while (b > 0)
    {

        if ((b & 1) == 1)
        {
            res = (res * a % MOD) % MOD;
        }

        a = (a % MOD * a % MOD) % MOD;
        b = b >> 1;
    }

    return res;
}

const int PRIME = 1e9 + 7;
const int N = 1000000;
int pw(int a, int p = PRIME - 2, int MOD = PRIME)
{
    int res = 1;
    while (p > 0)
    {
        if ((p & 1))
            res = a * res % MOD;

        a = a * a % MOD;
        p >>= 1;
    }
    return res;
}

int fact[N], invfact[N];
void init()
{
    int p = PRIME;
    fact[0] = 1;
    int i;
    for (i = 1; i < N; i++)
    {
        fact[i] = i * fact[i - 1] % p;
    }
    i--;
    invfact[i] = pw(fact[i], p - 2, p);
    i--;
    for (; i >= 0; i--)
    {
        invfact[i] = invfact[i + 1] * (i + 1) % p;
    }
}
int ncr(int n, int r)
{
    if (r > n || n < 0 || r < 0)
        return 0;
    return fact[n] * invfact[r] % PRIME * invfact[n - r] % PRIME;
}

int main()
{
    // int a, b, m;
    // cin >> a >> b >> m; // only if m is prime

    // int r1 = (a / b) % m;

    // a %= m;

    // int inv_b = fastPower(b, m - 2, m);

    // int r2 = a * inv_b % m; // fermat's little theorem

    // cout << r1 << " " << r2 << endl;

    init();
    cout << ncr(6, 2) << endl;

    return 0;
}