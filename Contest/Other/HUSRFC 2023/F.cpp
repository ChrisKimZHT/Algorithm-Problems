#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MAXN = 1e6 + 10;
int fact[MAXN];
int n, p;

int bpow(int a, int b)
{
    a %= p;
    int ans = 1;
    while (b)
    {
        if (b % 2)
            ans = ans * a % p;
        a = a * a % p;
        b /= 2;
    }
    return ans;
}

void init_fact()
{
    fact[0] = fact[1] = 1;
    for (int i = 2; i < p; i++)
        fact[i] = fact[i - 1] * i % p;
}

int calc(int n)
{
    if (n < p)
        return fact[n];
    int ans = bpow(fact[p - 1], n / p) * fact[n % p] % p;
    return calc(n / p) * ans % p;
}

void solve()
{
    cin >> n;
    cout << calc(n) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t >> p;
    init_fact();
    while (t--)
        solve();
    return 0;
}