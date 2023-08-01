#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> w(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    int ans = INT64_MAX;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0, cnt = 0;
        multiset<int> ms;
        for (int j = i; j <= n; j++)
        {
            if (w[j] < 0)
            {
                ms.insert(w[j]);
            }
            else
            {
                sum += w[j];
                cnt++;
            }
            if (sum >= k)
            {
                int tsum = sum, tcnt = cnt;
                for (auto ti = ms.rbegin(); ti != ms.rend(); ++ti)
                {
                    if (tsum + *ti < k)
                        break;
                    tsum += *ti;
                    tcnt++;
                }
                if (tcnt)
                    ans = min(ans, 2 * (j - i) - tcnt + 1);
            }
        }
    }
    if (ans == INT64_MAX)
        cout << -1 << endl;
    else
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