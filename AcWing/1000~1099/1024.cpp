#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int V;
    cin >> V;
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<bool> dp(V + 1);
    dp[0] = true;
    for (int i = 1; i <= n; i++)
        for (int j = V; j > 0; j--)
            if (j - a[i] >= 0 && dp[j - a[i]])
                dp[j] = true;
    int maxv = 0;
    for (int i = 0; i <= V; i++)
        if (dp[i])
            maxv = i;
    cout << V - maxv << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}