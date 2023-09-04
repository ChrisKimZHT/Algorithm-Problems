#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 10);
    vector<int> p(n + 10), s(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n - 1; i >= 1; i--)
    {
        s[i] = s[i + 1];
        if (a[i] >= a[i + 1])
            s[i]++;
    }
    for (int i = 2; i <= n; i++)
    {
        p[i] = p[i - 1];
        if (a[i - 1] <= a[i])
            p[i]++;
    }
    // for (int i = 1; i <= n; i++)
        // cout << p[i] << " \n"[i == n];
    // for (int i = 1; i <= n; i++)
        // cout << s[i] << " \n"[i == n];
    int ans = min(p[n] + 1, s[1]);
    for (int i = 1; i <= n; i++)
        ans = min(ans, p[i - 1] + s[i] + 1);
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