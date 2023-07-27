#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
        return a.first > b.first;
    return a.second < b.second;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 10);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] %= k;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
        if (a[i] == 0)
            ans.push_back(i + 1);
    vector<pair<int, int>> pr(n);
    for (int i = 0; i < n; i++)
        pr[i] = {a[i], i + 1};
    sort(pr.begin(), pr.end(), cmp);
    for (auto &p : pr)
        if (p.first != 0)
            ans.push_back(p.second);
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