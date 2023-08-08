#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 10);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int t = x * x - 4 * y;
        if (t < 0)
        {
            cout << 0 << ' ';
        }
        else if (t == 0)
        {
            int cnt = mp[x / 2];
            cout << cnt * (cnt - 1) / 2 << ' ';
        }
        else // if (t > 0)
        {
            int st = sqrt(t);
            if (st * st != t)
            {
                cout << 0 << ' ';
                continue;
            }
            int a = x + st;
            int b = x - st;
            if (a & 1)
            {
                cout << 0 << ' ';
                continue;
            }
            int ca = mp[a / 2];
            int cb = mp[b / 2];
            cout << ca * cb << ' ';
        }
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