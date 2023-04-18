#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    string s;
    cin >> s;
    if (s == "^")
    {
        cout << 1 << endl;
        return;
    }
    int cnt = 0;
    for (int i = 0; i < s.size() - 1; i++)
        if (s[i] == '_' && s[i + 1] == '_')
            cnt++;
    if (s.front() == '_')
        cnt++;
    if (s.back() == '_')
        cnt++;
    cout << cnt << endl;
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