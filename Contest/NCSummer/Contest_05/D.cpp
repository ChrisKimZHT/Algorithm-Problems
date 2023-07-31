#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int k, c, n;
    cin >> k >> c >> n;
    int ans = 0;
    for (int i = 1; i * i <= c; i++)
    {
        if (c % i == 0)
        {
            int t = c - c / i;
            if (t % k == 0)
            {
                int a = t / k;
                int b = c / i;
                if (a > 0 && b > 0)
                {
                    if (__gcd(a, b) >= n)
                        ans++;
                    // cout << a << ' ' << b << endl;
                }
            }
            if (i * i == c)
                continue;
            t = c - i;
            if (t % k == 0)
            {
                int a = t / k;
                int b = i;
                if (a > 0 && b > 0)
                {
                    if (__gcd(a, b) >= n)
                        ans++;
                    // cout << a << ' ' << b << endl;
                }
            }
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
    cin >> t;
    while (t--)
        solve();
    return 0;
}