#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    string s;
    cin >> s;
    for (int i = 0; i < 8; i++)
    {
        if ('1' + i == s[1])
            continue;
        cout << s[0] << char('1' + i) << endl;
    }
    for (int i = 0; i < 8; i++)
    {
        if ('a' + i == s[0])
            continue;
        cout << char('a' + i) << s[1] << endl;
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
    return 0;
}