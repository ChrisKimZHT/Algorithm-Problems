#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int cost = 0, now = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= now)
        {
            cost += a[i] - now;
            now++;
        }
    }
    cout << cost << endl;
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