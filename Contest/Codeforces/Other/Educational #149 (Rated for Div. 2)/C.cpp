#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int pos = s.find_first_not_of('?');
    if (pos == s.npos)
    {
        for (int i = 0; i < s.size(); i++)
            cout << 0;
        cout << endl;
        return;
    }
    for (int i = 0; i < pos; i++)
        cout << s[pos];
    char now = s[pos];
    for (int i = pos; i < s.size(); i++)
    {
        if (s[i] == '?')
            cout << now;
        else
        {
            cout << s[i];
            now = s[i];
        }
    }
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