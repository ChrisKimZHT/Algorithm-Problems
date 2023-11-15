#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    string s, t;
    cin >> s >> t;
    if (s.size() > t.size()) // s <= t
        swap(s, t);
    if (t.find(s) != s.npos)
        cout << s << " is substring of " << t << endl;
    else
        cout << "No substring" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}