#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

void solve()
{
    int n, w, h;
    cin >> n >> w >> h;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int l = INT32_MIN, r = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        int lim_l = a[i] - w, lim_r = a[i] + w;
        if (b[i] + l - h < lim_l)
            l = lim_l - b[i] + h;
        if (b[i] + r + h > lim_r)
            r = lim_r - b[i] - h;
        // cout << i << ": " << l << ' ' << r << endl;
        if (l > r)
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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