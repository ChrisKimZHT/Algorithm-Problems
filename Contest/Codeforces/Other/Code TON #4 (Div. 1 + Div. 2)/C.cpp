#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n, c, d;
    cin >> n >> c >> d;
    vector<int> a(n + 1), add(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int nn = a.size() - 1;
    for (int i = 1; i <= nn; i++)
        add[i] = add[i - 1] + (a[i] - a[i - 1] - 1) * d;
    int ans = n * c + d;
    for (int i = 1; i <= nn; i++)
        ans = min(ans, add[i] + (nn - i) * c + (n - nn) * c);
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}