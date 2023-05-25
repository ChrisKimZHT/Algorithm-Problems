#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (auto &ele : b)
        cin >> ele;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> trans(n);
    for (int i = 0; i < n; i++)
        trans[a[i].second] = i;
    for (int i = 0; i < n; i++)
        cout << b[trans[i]] << ' ';
    cout << endl;
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