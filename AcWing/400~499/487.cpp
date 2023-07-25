#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

const int MAXM = 80, MAXN = 4e4 + 10;
int N, m;
int v[MAXM], w[MAXM];
vector<int> sub[MAXN];
bool st[MAXN];
int dp[MAXM][MAXN];

void solve()
{
    cin >> N >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> v[i] >> w[i];
        w[i] *= v[i];
        int f;
        cin >> f;
        if (f == 0)
            continue;
        sub[f].push_back(i);
        st[i] = true;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (st[i])
                continue;
            if (j - v[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
            for (int k = 1; k < 1 << sub[i].size(); k++)
            {
                int vv = v[i], ww = w[i];
                for (int l = 0; l < sub[i].size(); l++)
                {
                    if (k >> l & 1)
                    {
                        vv += v[sub[i][l]];
                        ww += w[sub[i][l]];
                    }
                }
                // cout << vv << ' ' << ww << endl;
                if (j - vv >= 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - vv] + ww);
            }
        }
    }
    cout << dp[m][N] << endl;
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