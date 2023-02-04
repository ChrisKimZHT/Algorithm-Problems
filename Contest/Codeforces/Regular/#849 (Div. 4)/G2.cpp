#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        a[i] = {t + min(i + 1, n - i), t + i + 1};
    }
    sort(a.begin(), a.end());
    vector<int> ps(n + 1);
    for (int i = 1; i <= n; i++)
        ps[i] = (ps[i - 1] + a[i - 1].first);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int nc = c - a[i].second, mx = 0;
        int l = 0, r = n;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int tmp = ps[mid];
            int now = mid + 1;
            if (mid > i)
            {
                tmp -= a[i].first;
                now--;
            }
            if (tmp <= nc)
            {
                mx = max(now, mx);
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        ans = max(ans, mx);
    }
    cout << ans << endl;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}