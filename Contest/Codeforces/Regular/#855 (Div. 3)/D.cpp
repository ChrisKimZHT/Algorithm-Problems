#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int res = n - 1;
    for (int i = 1; i + 1 < n; i++)
        if (s[i - 1] == s[i + 1])
            res--;
    cout << res << endl;
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