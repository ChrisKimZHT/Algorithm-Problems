#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    int a, b;
    cin >> a;
    for (int i = 1; i < n; i++)
    {
    	cin >> b;
    	ans += abs(a - b);
    	a = b;
    }
    cin >> a;
    for (int i = 1; i < m; i++)
    {
    	cin >> b;
    	ans += abs(a - b);
    	a = b;
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