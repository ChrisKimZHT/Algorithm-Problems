// Problem: D. Cyclic Operations
// Contest: Codeforces - Codeforces Round 897 (Div. 2)
// URL: https://codeforces.com/contest/1867/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> nxt(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> nxt[i];
    if (k == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (nxt[i] != i)
            {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
        return;
    }
    vector<int> idx(n + 10), cir(n + 10);
    for (int i = 1; i <= n; i++)
    {
        if (idx[i])
            continue;
        int now = i;
        idx[now] = 1;
        cir[now] = i;
        while (!idx[nxt[now]])
        {
            idx[nxt[now]] = idx[now] + 1;
            cir[nxt[now]] = i;
            now = nxt[now];
        }
        int cnt = idx[now] - idx[nxt[now]] + 1;
        if (cir[nxt[now]] == i && cnt != k)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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