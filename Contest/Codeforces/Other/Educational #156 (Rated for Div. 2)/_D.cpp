#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MOD = 998244353;

int qpow(int a, int b)
{
    a %= MOD;
    int ans = 1;
    while (b)
    {
        if (b % 2)
            ans = ans * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    bool illegal = false;
    int ans = 1;
    if (s[0] == '?')
        illegal = true;
    for (int i = 1; i < s.size(); i++)
        if (s[i] == '?')
            ans = ans * i % MOD;
    cout << ans * (1 - illegal) << endl;
    for (int i = 0; i < m; i++)
    {
        int x;
        char c;
        cin >> x >> c;
        x--;
        if (s[x] == '?' && c != '?')
        {
            if (x == 0)
                illegal = false;
            else
                ans = ans * qpow(x, MOD - 2) % MOD;
        }
        else if (s[x] != '?' && c == '?')
        {
            if (x == 0)
                illegal = true;
            else
                ans = ans * x % MOD;
        }
        s[x] = c;
        cout << ans * (1 - illegal) << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;T
    while (t--)
        solve();
    return 0;
}