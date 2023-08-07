#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int bn = n * (n - 1) / 2;
    map<int, int> mp;
    for (int i = 1; i <= bn; i++)
    {
        int b;
        cin >> b;
        mp[b]++;
    }
    vector<int> ans;
    for (auto ti = mp.rbegin(); ti != mp.rend(); ++ti)
    {
        if (ans.empty())
        {
            ans.push_back(ti->first);
            ans.push_back(ti->first);
            ti->second--;
        }
        while (ti->second > 0)
        {
            ans.push_back(ti->first);
            ti->second -= ans.size() - 1;
        }
    }
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