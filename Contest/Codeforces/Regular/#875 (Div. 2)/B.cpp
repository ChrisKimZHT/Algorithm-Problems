#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> ma, mb;
    int la = -1, lb = -1;
    int ta = 0, tb = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (la == t)
        {
            ta++;
        }
        else
        {
            ma[la] = max(ma[la], ta);
            la = t;
            ta = 1;
        }
    }
    ma[la] = max(ma[la], ta);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (lb == t)
        {
            tb++;
        }
        else
        {
            mb[lb] = max(mb[lb], tb);
            lb = t;
            tb = 1;
        }
    }
    mb[lb] = max(mb[lb], tb);
    int ans = 0;
    for (auto &p : ma)
        ans = max(ans, p.second + mb[p.first]);
    for (auto &p : mb)
        ans = max(ans, p.second + ma[p.first]);
    cout << ans << endl;
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