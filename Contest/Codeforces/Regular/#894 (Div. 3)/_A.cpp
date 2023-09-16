// Problem: A. Gift Carpet
// Contest: Codeforces - Codeforces Round 894 (Div. 3)
// URL: https://codeforces.com/contest/1862/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

const string name = "vika";

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for (int i = 0; i < n; i++)
        cin >> mat[i];
    int now = 0;
    for (int j = 0; j < m; j++)
    {
        if (now == 4)
            break;
        for (int i = 0; i < n; i++)
        {
            if (mat[i][j] == name[now])
            {
                now++;
                break;
            }
        }
    }
    cout << (now == 4 ? "YES" : "NO") << endl;
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