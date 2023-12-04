// Problem: E. Collapsing Strings
// Contest: Codeforces - Educational Codeforces Round 159 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1902/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

const int MAXN = 1e6 + 10;
int son[MAXN][26], cnt[MAXN], idx;

void insert(string &s)
{
    int p = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int c = s[i] - 'a';
        if (!son[p][c])
            son[p][c] = ++idx;
        p = son[p][c];
        cnt[p]++;
    }
}

int query(string &s, int &ans)
{
    int p = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int c = s[i] - 'a';
        if (!son[p][c])
            return 0;
        p = son[p][c];
        ans -= 2 * cnt[p];
    }
    return cnt[p];
}

void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        ans += s[i].size();
        insert(s[i]);
    }
    ans *= 2 * n;
    for (int i = 0; i < n; i++)
    {
        reverse(s[i].begin(), s[i].end());
        query(s[i], ans);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}