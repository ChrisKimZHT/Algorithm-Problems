#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 10), b(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        b[i] -= a[i];
    }
    int mn = INT32_MAX;
    for (int i = 1; i <= n; i++)
        mn = min(b[i], mn);
    vector<int> ans;
    for (int i = 1; i <= n; i++)
        if (b[i] == mn)
            ans.push_back(i);
    cout << ans.size() << endl;
    for (auto &ele : ans)
        cout << ele << ' ';
    cout << endl;
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