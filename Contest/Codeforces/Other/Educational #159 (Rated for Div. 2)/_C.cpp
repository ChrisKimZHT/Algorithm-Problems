// Problem: C. Insert and Equalize
// Contest: Codeforces - Educational Codeforces Round 159 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1902/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    sort(a.begin(), a.end());
    int gap = a[1] - a[0];
    for (int i = 2; i < n; i++)
        gap = gcd(gap, a[i] - a[i - 1]);
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += (a[n - 1] - a[i]) / gap;
    bool flag = false;
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] - a[i - 1] != gap)
        {
            ans += (a[n - 1] - (a[i] - gap)) / gap;
            flag = true;
            break;
        }
    }
    if (!flag)
        ans += n;
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