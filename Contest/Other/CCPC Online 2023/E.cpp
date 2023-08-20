#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

constexpr int MAXN = 22;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
map<char, int> mp = {{'L', 0}, {'R', 1}, {'D', 2}, {'U', 3}};

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    set<pair<int, int>> st;
    for (int i = 0; i < (1 << n); i++)
    {
        set<pair<int, int>> yes, no;
        yes.insert({0, 0});
        int pos_x = 0, pos_y = 0;
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            if (i >> j & 1)
            {

                pos_x += dx[mp[s[j]]];
                pos_y += dy[mp[s[j]]];
                if (no.count({pos_x, pos_y}))
                {
                    flag = false;
                    break;
                }
                yes.insert({pos_x, pos_y});
            }
            else
            {
                if (yes.count({pos_x + dx[mp[s[j]]], pos_y + dy[mp[s[j]]]}))
                {
                    flag = false;
                    break;
                }
                no.insert({pos_x + dx[mp[s[j]]], pos_y + dy[mp[s[j]]]});
            }
        }
        if (flag)
        {
            st.insert({pos_x, pos_y});
        }
    }
    cout << st.size() << endl;
    for (auto &[x, y] : st)
    {
        cout << x << ' ' << y << endl;
    }
}

signed main()
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