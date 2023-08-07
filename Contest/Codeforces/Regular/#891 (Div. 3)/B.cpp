#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int pos = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '5')
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        cout << s << endl;
        return;
    }
    for (int i = pos; i > 0; i--)
    {
        s[i] = '0';
        s[i - 1]++;
        if (s[i - 1] < '5')
            break;
    }
    if (s[0] >= '5')
    {
        cout << '1';
        s[0] = '0';
    }
    for (int i = pos + 1; i < s.size(); i++)
        s[i] = '0';
    cout << s << endl;
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