// Problem: F. Selling a Menagerie
// Contest: Codeforces - Codeforces Round 895 (Div. 3)
// URL: https://codeforces.com/contest/1872/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MAXN = 1e5 + 10;
int a[MAXN], c[MAXN], d[MAXN];
bool st[MAXN];

void calc(vector<int> &arr)
{
    int mn = INT32_MAX, pos = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (c[arr[i]] < mn)
        {
            mn = c[arr[i]];
            pos = i;
        }
    }
    pos++;
    for (int i = 0; i < arr.size(); i++)
        cout << arr[(i + pos) % arr.size()] << ' ';
}

void solve()
{
    memset(a, -1, sizeof(a));
    memset(c, -1, sizeof(c));
    memset(d, 0, sizeof(d));
    memset(st, false, sizeof(st));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    queue<int> que;
    for (int i = 1; i <= n; i++)
        if (d[i] == 0)
            que.push(i);
    while (que.size())
    {
        int now = que.front();
        st[now] = true;
        que.pop();
        cout << now << ' ';
        d[a[now]]--;
        if (d[a[now]] == 0)
            que.push(a[now]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (st[i])
            continue;
        vector<int> arr;
        arr.push_back(i);
        st[i] = true;
        while (!st[a[arr.back()]])
        {
            st[a[arr.back()]] = true;
            arr.push_back(a[arr.back()]);
        }
        calc(arr);
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