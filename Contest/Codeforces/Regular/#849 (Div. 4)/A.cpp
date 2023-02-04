#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const string cf = "codeforces";

void solve()
{
    string c;
    cin >> c;
    if (cf.find(c) == cf.npos)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
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