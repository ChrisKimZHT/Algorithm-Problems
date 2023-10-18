// Problem: C. Perfect Square
// Contest: Codeforces - Codeforces Round 903 (Div. 3)
// URL: https://codeforces.com/contest/1881/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> mat(n);
    for (int i = 0; i < n; i++)
        cin >> mat[i];
    int cnt = 0;
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            auto &lu = mat[i][j];
            auto &ru = mat[j][n - 1 - i];
            auto &ld = mat[n - 1 - j][i];
            auto &rd = mat[n - 1 - i][n - 1 - j];
            int mx = max({lu, ru, ld, rd});
            cnt += 4 * mx - (lu + ru + ld + rd);
        }
    }
    cout << cnt << endl;
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