#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> b(n + 10);
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == a[i + 1])
            b[i] = b[i + 1];
        else
            b[i] = i;
    }
    // for (int i = 1; i <= n; i++)
    //     cout << b[i] << " \n"[i == n];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int now = i;
        now = b[now];
        if (now != n)
            now = b[now + 1];
        if (now != n)
            now = b[now + 1];
        if (now != n && a[i] == 1)
            now = b[now + 1];
        ans = max(ans, now - i + 1);
    }
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