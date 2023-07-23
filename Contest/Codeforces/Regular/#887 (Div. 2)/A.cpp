#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a;
    cin >> a;
    int ans = INT32_MAX, last = a;
    for (int i = 1; i < n; i++)
    {
        cin >> a;
        if (a < last)
            ans = 0;
        ans = min(ans, (a - last) / 2 + 1);
        last = a;
    }
    cout << max(0, ans) << endl;
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