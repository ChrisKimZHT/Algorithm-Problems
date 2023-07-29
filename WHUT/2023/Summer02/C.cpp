#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int b;
    cin >> b;
    int ans = 0;
    for (int i = 1; i * i <= b; i++)
    {
        if (b % i == 0)
        {
            ans++;
            if (i * i != b)
                ans++;
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