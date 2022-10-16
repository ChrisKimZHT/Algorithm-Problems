#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 2e5 + 10;
vector<int> son[MAXN];
int s[MAXN], f[MAXN], g[MAXN];

void dfs(int x, int n)
{
    f[x] = s[x] * n;
    g[x] = s[x] * (n + 1);
    if (son[x].empty())
        return;
    int k = n / son[x].size();
    int p = n % son[x].size();
    vector<int> delta;
    for (auto s : son[x])
    {
        dfs(s, k);
        f[x] += f[s];
        g[x] += f[s];
        delta.push_back(g[s] - f[s]);
    }
    sort(delta.begin(), delta.end(), greater<int>());
    for (int i = 0; i < p; i++)
    {
        f[x] += delta[i];
        g[x] += delta[i];
    }
    g[x] += delta[p];
    return;
}

void solve()
{
    for (int i = 0; i < MAXN; i++)
        son[i].clear();
    int n, k;
    cin >> n >> k;
    for (int i = 2; i <= n; i++)
    {
        int t;
        cin >> t;
        son[t].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    dfs(1, k);
    cout << f[1] << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}