#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N, V;
    cin >> N >> V;
    vector<int> dp(V + 10);
    for (int i = 1; i <= N; i++)
    {
        int v, w, s;
        cin >> v >> w >> s;
        if (s == 0)
        {
            for (int j = v; j <= V; j++)
                dp[j] = max(dp[j], dp[j - v] + w);
        }
        else
        {
            s = abs(s);
            vector<int> vv, ww;
            int k = 1;
            while (k <= s)
            {
                vv.push_back(v * k);
                ww.push_back(w * k);
                s -= k;
                k *= 2;
            }
            if (s)
            {
                vv.push_back(v * s);
                ww.push_back(w * s);
            }
            for (int j = 0; j < vv.size(); j++)
                for (int k = V; k >= vv[j]; k--)
                    dp[k] = max(dp[k], dp[k - vv[j]] + ww[j]);
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