#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin() + 1, a.begin() + 1 + n);
    vector<int> ans(n + 10);
    int awa = 0;
    for (int i = 1; i <= n; i++)
        awa += abs(a[i].first - a[1].first) + 1;
    ans[a[1].second] = awa;
    for (int i = 2; i <= n; i++)
    {
        int cnt_p = i - 1;
        int cnt_s = n - i;
        awa += (cnt_p - cnt_s - 1) * (a[i].first - a[i - 1].first);
        ans[a[i].second] = awa;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
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