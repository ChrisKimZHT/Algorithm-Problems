// Problem: B. Two Out of Three
// Contest: Codeforces - Codeforces Round 908 (Div. 2)
// URL: https://codeforces.com/contest/1894/problem/B
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    int cnt = 0;
    for (auto &[key, val] : mp)
        if (val >= 2)
            cnt++;
    if (cnt < 2)
    {
        cout << -1 << endl;
        return;
    }
    int need = 2;
    set<int> used;
    for (int i = 0; i < n; i++)
    {
        if (need == 0)
        {
            cout << 1 << ' ';
            continue;
        }
        if (mp[a[i]] < 2)
        {
            cout << 1 << ' ';
        }
        else
        {
            if (used.count(a[i]) == 0)
            {
                cout << need + 1 << ' ';
                need--;
                used.insert(a[i]);
            }
            else
            {
                cout << 1 << ' ';
            }
        }
    }
    cout << endl;
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