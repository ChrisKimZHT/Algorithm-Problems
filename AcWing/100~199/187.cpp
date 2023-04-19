#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 100;
int n, ans;
int a[MAXN], up[MAXN], down[MAXN];

void dfs(int now, int cu, int cd)
{
    if (cu + cd >= ans)
    {
        return;
    }
    if (now == n)
    {
        ans = cu + cd;
        return;
    }

    int k = 0;
    while (k < cu && up[k] >= a[now])
        k++;
    int t = up[k];
    up[k] = a[now];
    if (k < cu)
        dfs(now + 1, cu, cd);
    else
        dfs(now + 1, cu + 1, cd);
    up[k] = t;

    k = 0;
    while (k < cd && down[k] <= a[now])
        k++;
    t = down[k];
    down[k] = a[now];
    if (k < cd)
        dfs(now + 1, cu, cd);
    else
        dfs(now + 1, cu, cd + 1);
    down[k] = t;
};

void solve()
{
    while (cin >> n, n)
    {
        ans = n;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        dfs(0, 0, 0);
        cout << ans << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}