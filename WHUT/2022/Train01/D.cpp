#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int sum = accumulate(a.begin(), a.end(), 0LL);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        int pos = lower_bound(a.begin(), a.end(), x) - a.begin(), ans;
        if (pos < n && a[pos] >= x)
        {
            ans = max(0LL, y - (sum - a[pos]));
            if (pos)
                ans = min(ans, max(0LL, y - (sum - a[pos - 1])) + (x - a[pos - 1]));
        }
        else if (pos < n)
        {
            ans = (x - a[pos]) + max(0LL, y - (sum - a[pos]));
        }
        else
        {
            ans = (x - a[pos - 1]) + max(0LL, y - (sum - a[pos - 1]));
        }
        cout << ans << endl;
    }
    return 0;
}