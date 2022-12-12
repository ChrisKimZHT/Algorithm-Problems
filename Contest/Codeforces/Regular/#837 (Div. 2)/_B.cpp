#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int MAXN = 1e5 + 10;
int n, m;
int a[MAXN];

void solve()
{
    memset(a, 0, sizeof(a));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x < y)
            swap(x, y);
        a[x] = max(a[x], y);
    }
    for (int i = 2; i <= n; i++)
        a[i] = max(a[i], a[i - 1]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += i - a[i];
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