#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int cnt1 = 0, cnt2 = 0;
    if (x1 == 1 || x1 == n)
        cnt1++;
    if (y1 == 1 || y1 == m)
        cnt1++;
    if (x2 == 1 || x2 == n)
        cnt2++;
    if (y2 == 1 || y2 == m)
        cnt2++;
    cout << min(4 - cnt1, 4 - cnt2) << endl;
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