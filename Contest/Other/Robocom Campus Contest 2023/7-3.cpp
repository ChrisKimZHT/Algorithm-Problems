#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int base = 0;
    vector<int> a(n + 1);
    unordered_map<int,
                  pair<priority_queue<int>,
                       priority_queue<int, vector<int>, greater<int>>>>
        mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        base += (n / i) * a[i];
        mp[n / i].first.push(a[i]);
        mp[n / i].second.push(a[i]);
    }
    int opti = 0;
    for (auto &p : mp)
        for (auto &q : mp)
            opti = max(opti, (p.first - q.first) * (p.second.second.top() - q.second.first.top()));
    cout << base - opti << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}