#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<pair<int, int>> rw(m);
    for (int i = 0; i < m; i++)
        cin >> rw[i].first >> rw[i].second;
    sort(rw.begin(), rw.end());
    int now = 0, mn = INT32_MAX, pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < mn)
        {
            mn = a[i];
            pos = i;
        }
        while (now < m && rw[now].first == i + 1)
        {
            a[pos] -= rw[now].second;
            mn -= rw[now].second;
            now++;
        }
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        if (i)
        {
            cout << ' ';
            a[i] += a[i - 1];
        }
        cout << a[i];
    }
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