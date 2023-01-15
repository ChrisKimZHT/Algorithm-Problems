#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

bool is_square(int n)
{
    int r = sqrt(1.0L * n);
    return r * r == n;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int t = a[j] - a[i];
            for (int p = 1; p * p <= t; p++)
            {
                if (t % p)
                    continue;
                int q = t / p;
                if ((q - p) % 2)
                    continue;
                int u = (q - p) / 2, v = (q + p) / 2;
                int x = u * u - a[i];
                if (x < 0)
                    continue;
                int res = 0;
                for (int ii = 0; ii < n; ii++)
                    if (is_square(a[ii] + x))
                        res++;
                ans = max(ans, res);
            }
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}