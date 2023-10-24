#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cout << i << ' ' << i << endl;
        cout << i << ' ' << ((i - 1) + 1) % n + 1 << endl;
    }
    k -= 2 * n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
    		if (!k)
    			return;
    		if (i == j || i == j - 1 || (i == n && j == 1))
    			continue;
    		cout << i << ' ' << j << endl;
    		k--;
        }
    }
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