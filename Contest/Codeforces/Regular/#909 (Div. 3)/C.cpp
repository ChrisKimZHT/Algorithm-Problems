#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = INT64_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans = max(a[i], ans);
    }
    int tmp = a[0];
    for (int i = 1; i < n; i++)
    {
        if ((a[i] % 2 + 2) % 2 == (a[i - 1] % 2 + 2) % 2)
        {
            ans = max(ans, tmp);
            tmp = 0;
        }
        tmp = max(0LL, tmp);
        tmp += a[i];
        ans = max(ans, tmp);
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