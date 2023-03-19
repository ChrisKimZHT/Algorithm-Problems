#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n, t;
    cin >> n >> t;
    vector<pair<int, pair<int, int>>> xd(n);
    for (int i = 0; i < n; i++)
    {
        cin >> xd[i].first >> xd[i].second.first;
        xd[i].second.second = i;
    }
    sort(xd.begin(), xd.end());
    vector<int> mp(n);
    for (int i = 0; i < n; i++)
        mp[xd[i].second.second] = i;
    vector<int> ans;
    for (int i = 0; i < n; i++)
        ans.push_back(xd[i].first + xd[i].second.first * t);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < n; i++)
        cout << ans[mp[i]] << ' ';
    cout << endl;
}

int main()
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