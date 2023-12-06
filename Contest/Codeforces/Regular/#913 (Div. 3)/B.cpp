#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    string s;
    cin >> s;
    vector<int> low, upp;
    vector<char> ans;
    vector<bool> vis;
    for (int i = 0; i < s.size(); i++)
    {
        char &c = s[i];
        ans.push_back(c);
        vis.push_back(false);
        if (c == 'b')
        {
            vis[i] = true;
            if (low.empty())
                continue;
            vis[low.back()] = true;
            low.pop_back();
        }
        else if (c == 'B')
        {
            vis[i] = true;
            if (upp.empty())
                continue;
            vis[upp.back()] = true;
            upp.pop_back();
        }
        else
        {
            if (isupper(c))
                upp.push_back(i);
            else
                low.push_back(i);
        }
    }
    for (int i = 0; i < ans.size(); i++)
        if (!vis[i])
            cout << ans[i];
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