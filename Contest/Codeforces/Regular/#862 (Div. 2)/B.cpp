#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    char minchar = 'z' + 1;
    int minpos = -1;
    for (int i = 0; i < n; i++)
    {
        if (minchar >= s[i])
        {
            minchar = s[i];
            minpos = i;
        }
    }
    s.erase(s.begin() + minpos);
    cout << minchar << s << endl;
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