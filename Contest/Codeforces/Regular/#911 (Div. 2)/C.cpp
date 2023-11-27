// Problem: C. Anji's Binary Tree
// Contest: Codeforces - Codeforces Round 911 (Div. 2)
// URL: https://codeforces.com/contest/1900/problem/C
// Memory Limit: 256 MB
// Time Limit: 2500 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

int n;
string s;
vector<pair<int, int>> son;

int dfs(int now, int fa)
{
    int ans = INT32_MAX;
    if (son[now].first)
        ans = min(ans, dfs(son[now].first, now) + (s[now] != 'L'));
    if (son[now].second)
        ans = min(ans, dfs(son[now].second, now) + (s[now] != 'R'));
    if (ans == INT32_MAX)
    	ans = 0;
    return ans;
}

void solve()
{
    cin >> n;
    cin >> s;
    s = " " + s;
    son.resize(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> son[i].first >> son[i].second;
    cout << dfs(1, 0) << endl;
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