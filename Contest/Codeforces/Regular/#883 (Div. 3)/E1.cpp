#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    for (int i = 2; i * i <= n; i++)
    {
        int t = n, cnt = 0;
        while (t)
        {
            if ((t - 1) % i)
            {
                cnt = 0;
                break;
            }
            t = (t - 1) / i;
            cnt++;
        }
        if (cnt >= 2)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
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