#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int up = a, down = a;
        while (down % 2 == 0)
        {
            down /= 2;
            up--;
        }
        mp[{up, down}]++;
    }
    int ans = 0;
    for (auto &[key, val] : mp)
        ans += val * (val - 1) / 2;
    cout << ans << endl;
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