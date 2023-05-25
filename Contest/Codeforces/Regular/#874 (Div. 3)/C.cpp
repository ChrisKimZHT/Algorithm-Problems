#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int cnt_odd = 0, min_odd = INT32_MAX, min_all = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        min_all = min(min_all, t);
        if (t % 2)
        {
            cnt_odd++;
            min_odd = min(min_odd, t);
        }
    }
    if (min_all == min_odd ||
        cnt_odd == 0 ||
        cnt_odd == n)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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