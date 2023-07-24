#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

const int MAXN = 5e5 + 10;
int e[MAXN], ne[MAXN], h[MAXN], cnt;
int a[MAXN];
int dp[MAXN][2];

void add(int x, int y)
{
    e[cnt] = y;
    ne[cnt] = h[x];
    h[x] = cnt++;
}

void dfs(int now)
{
    dp[now][1] = INT64_MIN;
    for (int i = h[now]; i != -1; i = ne[i])
    {
        int &nxt = e[i];
        dfs(nxt);
        int now1 = dp[now][1], now0 = dp[now][0];
        dp[now][0] = max(dp[nxt][1] + now1, dp[nxt][0] + now0);
        dp[now][1] = max(dp[nxt][1] + now0, dp[nxt][0] + now1);
    }
    dp[now][1] = max(dp[now][1], dp[now][0] + a[now]);
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p >> a[i];
        if (p == -1)
            continue;
        add(p, i);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(h, -1, sizeof(h));
    solve();
    return 0;
}