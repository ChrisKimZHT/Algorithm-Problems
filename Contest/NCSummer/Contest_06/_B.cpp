#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MAXN = 4e3 + 10, MOD = 998244353;
int comb[MAXN][MAXN];

void init_comb()
{
    for (int i = 0; i < MAXN; i++)
        comb[i][0] = 1;
    for (int i = 1; i < MAXN; i++)
        for (int j = 1; j < MAXN; j++)
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
}

int n;
int a[MAXN], b[MAXN];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int pi = i - 1, pj = j - 1;
            int si = n - i, sj = n - j;
            int pcnt = comb[pi + pj][min(pi, pj)];
            int scnt = comb[si + sj][min(si, sj)];
            int delta = abs(a[i] - b[j]) % MOD;
            ans = (ans + pcnt * scnt % MOD * delta % MOD) % MOD;
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init_comb();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}