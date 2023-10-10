#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    int t = 1, l = s.size();
    while (t + l <= n)
    {
        t += l;
        l--;
    }
    vector<int> del;
    vector<bool> vis(s.size());
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i - 1] > s[i])
        {
            del.push_back(i - 1);
            vis[i - 1] = true;
        }
    }
    for (int i = s.size() - 1; i >= 0; i--)
        if (!vis[i])
            del.push_back(i);
    int now = 0;
    vector<bool> st(s.size());
    for (int i = 0; i < s.size() - l; i++)
    {
        st[del[now]] = true;
        now++;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (st[i])
            continue;
        n--;
        if (n - t + 1 == 0)
            cout << s[i];
    }
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
    cout << endl;
    return 0;
}