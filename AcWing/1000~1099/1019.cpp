#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N, V;
    cin >> N >> V;
    vector<int> v(N + 10), w(N + 10), s(N + 10);
    for (int i = 1; i <= N; i++)
        cin >> v[i] >> w[i] >> s[i];
    vector<int> dp(V + 10), lst(V + 10);
    vector<int> que(V + 10);
    for (int i = 1; i <= N; i++)
    {
        lst = dp;
        for (int r = 0; r < v[i]; r++)
        {
            int hh = 0, tt = -1;
            for (int k = r; k <= V; k += v[i])
            {
                if (hh <= tt && que[hh] < k - s[i] * v[i])
                    ++hh;
                while (hh <= tt && lst[que[tt]] - (que[tt] - r) / v[i] * w[i] <= lst[k] - (k - r) / v[i] * w[i])
                    --tt;
                if (hh <= tt)
                    dp[k] = max(dp[k], lst[que[hh]] + (k - que[hh]) / v[i] * w[i]);
                que[++tt] = k;
            }
        }
    }
    cout << dp[V] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
