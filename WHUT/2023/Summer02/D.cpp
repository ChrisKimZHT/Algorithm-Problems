#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

constexpr int MAXN = 1e5 + 10;
int ans[MAXN], tmp[MAXN];

bool calc(int l, int r, int k)
{
    if (l + 1 == r)
    {
        if (k > 1)
            return false;
        tmp[l] = r;
        return true;
    }
    if (k == 0)
        return false;
    if (k == 1)
    {
        for (int i = l; i < r; i++)
            tmp[i] = i + 1;
        return true;
    }
    int rk = (k - 1) / 2;
    int lk = k - 1 - rk;
    if (lk % 2 == 0)
    {
        lk++;
        rk--;
    }
    if (lk == 0 || rk == 0)
        return false;
    int mid = (l + r + 1) / 2;
    if (!calc(l, mid, lk))
        return false;
    if (!calc(mid, r, rk))
        return false;
    for (int i = 0; i < r - mid; i++)
        ans[l + i] = tmp[i + mid];
    for (int i = r - mid; i < r - l; i++)
        ans[l + i] = tmp[i - r + mid + l];
    memcpy(tmp, ans, sizeof(tmp));
    return true;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    bool st = calc(0, n, k);
    if (!st)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < n; i++)
        cout << tmp[i] << ' ';
    cout << endl;
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