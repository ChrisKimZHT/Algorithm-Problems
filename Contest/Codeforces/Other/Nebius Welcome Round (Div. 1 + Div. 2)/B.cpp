#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, d, w;
    cin >> n >> k >> d >> w;
    int ans = 0, rem = 0, exp = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (rem == 0 || exp < t)
        {
            ans++;
            rem = k - 1;
            exp = t + d + w;
        }
        else
        {
            rem--;
        }
    }
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