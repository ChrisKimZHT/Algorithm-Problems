#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (!flag && s[i] - '0' < d)
        {
            cout << d;
            flag = true;
        }
        cout << s[i];
    }
    if (!flag)
        cout << d;
    cout << endl;
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