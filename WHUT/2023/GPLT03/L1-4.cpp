#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    double ans = 0.0;
    for (int i = 0; i < n; i++)
    {
        double t;
        cin >> t;
        ans += 1.0 / t;
    }
    ans /= n;
    ans = 1.0 / ans;
    cout << fixed << setprecision(2) << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}