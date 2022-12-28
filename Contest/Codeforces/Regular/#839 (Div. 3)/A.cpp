#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    string s;
    cin >> s;
    cout << s[0] - '0' + s[2] - '0' << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}