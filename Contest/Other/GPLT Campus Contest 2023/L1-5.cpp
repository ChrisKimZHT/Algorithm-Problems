#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n % 11 == 0)
    {
        cout << "Yes" << endl;
        return;
    }
    string s = to_string(n);
    if (s.find("11") != s.npos)
    {
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
}

int main()
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