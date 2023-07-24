#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    string s;
    cin >> s;
    string t;
    cin >> t;
    int x = 0, y = 0;
    for (int i = 0; i < s.length(); i++)
    {
        x <<= 1;
        x += s[i] - '0';
    }
    for (int i = 0; i < t.length(); i++)
    {
        y <<= 1;
        y += t[i] - '0';
    }
    if (x == 0 && x != y)
    {
        cout << "-1\n";
        return;
    }
    cout << abs(y - x) << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
