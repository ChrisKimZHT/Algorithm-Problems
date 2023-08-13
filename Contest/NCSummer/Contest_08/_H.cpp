#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MAXN = 1e6 + 10;
vector<int> p[MAXN], s;

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            p[1].push_back(i);
            s.push_back(i);
            ans += s.size();
        }
        else if (p[x - 1].empty())
        {
            s.clear();
        }
        else
        {
            int y = p[x - 1].back();
            p[x - 1].pop_back();
            p[x].push_back(y);
            while (s.size() && s.back() > y)
                s.pop_back();
            ans += s.size();
        }
    }
    cout << ans << endl;
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