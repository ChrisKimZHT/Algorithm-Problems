#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MAXN = 5e5 + 10;

int a[MAXN], q[MAXN];
double p[MAXN];
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> q[i];
    for (int i = 0; i < n; i++)
        p[i] = q[i] * 1.0 / 100000.0;
    double ans = n;
    for (int i = 0; i < n; i++)
    {
        if (q[i] == 0)
            continue;
        ans = min(ans, a[i] + (i - a[i] + 1) * 1.0 / p[i]);
    }
    cout << fixed << setprecision(12) << ans << endl;
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
