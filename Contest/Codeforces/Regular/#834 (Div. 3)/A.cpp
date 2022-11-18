#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    string t;
    for (int i = 0; i < 20; i++)
        t += "Yes";
    if (t.find(s) != t.npos)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}