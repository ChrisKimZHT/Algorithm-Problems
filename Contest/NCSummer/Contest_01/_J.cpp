#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long ll;
const int MAXN = 60, MOD = 998244353;

ll quick_pow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b % 2)
            res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

ll pow2[MAXN];
void init_pow2()
{
    pow2[0] = 1;
    for (int i = 1; i < MAXN; i++)
        pow2[i] = pow2[i - 1] * 2;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int cur = 0;
    while (pow2[cur + 1] - 1 <= n)
        cur++;
    ll up = 1, down = 1;
    int now = n, nxt;
    while (pow2[cur] <= n + m)
    {
        nxt = min(ll(n + m), pow2[cur + 1] - 1);
        up = up * quick_pow(pow2[cur] - 1, nxt - now) % MOD;
        down = down * quick_pow(pow2[cur], nxt - now) % MOD;
        cur++;
        now = nxt;
    }
    cout << up * quick_pow(down, MOD - 2) % MOD << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init_pow2();
    solve();
    return 0;
}