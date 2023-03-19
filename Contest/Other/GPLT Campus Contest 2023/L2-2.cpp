#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int MAXN = 15;
int g[MAXN][MAXN];

int get_dist(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> pos(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> pos[i].first >> pos[i].second;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            g[i][j] = get_dist(pos[i], pos[j]);
    for (int i = 1; i <= n; i++)
    {
        g[i][0] = 0;
        g[0][i] = get_dist({0, 0}, pos[i]);
    }
    for (int k = 0; k <= n; k++)
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        vector<bool> vis(n + 1);
        int now = i, rem = n - 1, res = get_dist({0, 0}, pos[i]);
        vis[now] = true;
        while (rem)
        {
            int t = -1;
            for (int j = 1; j <= n; j++)
                if (!vis[j] && (t == -1 || g[now][j] < g[now][t]))
                    t = j;
            res += g[now][t];
            now = t;
            vis[t] = true;
            rem--;
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}