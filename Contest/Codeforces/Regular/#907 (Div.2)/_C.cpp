// Problem: C. Smilo and Monsters
// Contest: Codeforces - Codeforces Round 907 (Div. 2)
// URL: https://codeforces.com/contest/1891/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MAXN = 2e5 + 10;
int a[MAXN];

void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + 1 + n);
    int ans = 0, l = 1;
    for (int r = n; r >= 1; r--)
    {
        if (l > r)
            break;
        if (a[r] * 2 > sum)
        {
			if (sum == 1)
				ans += 1;
			else
				ans += (sum + 1) / 2 + 1;
        	break;
        }
        int t = a[r];
        while (true)
        {
            if (t < a[l])
            {
                a[l] -= t;
                break;
            }
            t -= a[l];
            l++;
        }
        sum -= a[r] * 2;
        ans += a[r] + 1;
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