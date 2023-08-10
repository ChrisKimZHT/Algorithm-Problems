#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

bool check(vector<int> &a)
{
    int n = a.size();
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        p[(i + 1) % n] = a[(i + 1) % n] - p[i];
    bool op = true; // 1+ 0-
    int l = 0, r = a.front();
    for (int i = 0; i < n; i++)
    {
        if (op)
            l = max(l, -p[i]);
        else
            r = min(r, p[i]);
        if (l > r)
            return false;
        op ^= 1;
    }
    if (n & 1)
    {
        if (p.front() & 1)
            return false;
        int ans = p.front() / 2;
        return l <= ans && ans <= r;
    }
    return p.front() == 0;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool all_zero = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i])
        {
            all_zero = false;
            break;
        }
    }
    if (all_zero)
    {
        cout << "YES" << endl;
        return;
    }
    if (2 * k > n)
    {
        cout << "NO" << endl;
        return;
    }
    vector<bool> vis(n + 10);
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        vector<int> ring;
        int pos = i;
        while (!vis[pos])
        {
            vis[pos] = true;
            ring.push_back(a[pos]);
            pos = (pos + k) % n;
        }
        if (!check(ring))
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
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