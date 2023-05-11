#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int min_1 = INT32_MAX, min_2 = INT32_MAX, min_3 = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        int m;
        string s;
        cin >> m >> s;
        if (s == "10")
            min_1 = min(min_1, m);
        else if (s == "01")
            min_2 = min(min_2, m);
        else if (s == "11")
            min_3 = min(min_3, m);
    }
    if ((min_1 == INT32_MAX || min_2 == INT32_MAX) && min_3 == INT32_MAX)
    {
        cout << -1 << endl;
        return;
    }
    cout << min(min_1 + min_2, min_3) << endl;
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