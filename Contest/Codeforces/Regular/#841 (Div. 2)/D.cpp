#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 1e6 + 10;
int n, m;
int que[MAXN];

void get_min(vector<int> &a, vector<int> &f, int m, int k)
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= m; i++)
    {
        while (hh <= tt && i - que[hh] >= k)
            hh++;
        while (hh <= tt && a[i] <= a[que[tt]])
            tt--;
        que[++tt] = i;
        f[i] = a[que[hh]];
    }
}

bool check(int mid, vector<vector<int>> &mat)
{
    vector mmin(n + 10, vector<int>(m + 10));
    for (int i = 1; i <= n; i++)
        get_min(mat[i], mmin[i], m, mid);
    vector<int> b(n + 10), d(n + 10);
    int res = 0;
    for (int i = mid; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            b[j] = mmin[j][i];
        get_min(b, d, n, mid);
        for (int j = mid; j <= n; j++)
            res = max(res, d[j]);
    }
    return res >= mid;
}

void solve()
{
    cin >> n >> m;
    vector a(n + 10, vector<int>(m + 10));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    int l = 1, r = min(n, m);
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (check(mid, a))
            l = mid;
        else
            r = mid - 1;
    }
    cout << r << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}