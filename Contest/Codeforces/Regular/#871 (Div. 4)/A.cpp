#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const string cf = "codeforces";

void solve()
{
    string s;
    cin >> s;
    int n = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != cf[i])
            n++;
    cout << n << endl;
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