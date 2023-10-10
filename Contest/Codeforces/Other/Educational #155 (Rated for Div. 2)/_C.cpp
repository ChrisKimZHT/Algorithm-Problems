#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MOD = 998244353;
constexpr int MAXN = 2e5 + 10;
int fact[MAXN];

void init_fact()
{
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = fact[i - 1] * i % MOD;
}

void solve()
{
    string s;
    cin >> s;
    int del_cnt = 0, op_cnt = 1;
    int cnt = 0;
    for (int i = 1; i <= s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            cnt++;
        }
        else if (cnt)
        {
            del_cnt += cnt;
            op_cnt = op_cnt * (cnt + 1) % MOD;
            cnt = 0;
        }
    }
    op_cnt = op_cnt * fact[del_cnt] % MOD;
    cout << del_cnt << ' ' << op_cnt << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    init_fact();
    while (t--)
        solve();
    return 0;
}