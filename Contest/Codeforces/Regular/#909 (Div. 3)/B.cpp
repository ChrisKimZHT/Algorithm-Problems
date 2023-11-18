#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int mx = 0, mn = INT64_MAX;
        if (n % i == 0)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += a[j];
                if ((j + 1) % i == 0)
                {
                    mx = max(mx, sum);
                    mn = min(mn, sum);
                    sum = 0;
                }
            }
        }
        ans = max(ans, mx - mn);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}