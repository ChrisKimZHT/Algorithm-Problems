#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0, st = -1;
    for (int i = 2; i <= n; i++)
    {
        if (st == -1)
        {
            if (abs(a[i] - a[i - 1]) == 1)
            {
                if (a[i - 1] < a[i])
                    st = 1;
                else
                    st = 0;
            }
            else
            {
            	ans++;
            }
            continue;
        }
        if (abs(a[i] - a[i - 1]) == 1)
        {
            if (a[i - 1] < a[i])
            {
                if (st == 0)
                {
                    ans++;
                    st = 0;
                }
            }
            else
            {
                if (st == 1)
                {
                    ans++;
                    st = 1;
                }
            }
        }
        else
        {
            ans++;
            st = -1;
        }
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