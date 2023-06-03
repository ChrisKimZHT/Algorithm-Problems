#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int lim = sqrt(n * 2);
    vector<int> a(n), b(n);
    vector<vector<signed>> mat(lim + 10, vector<signed>(n + 10));
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (a[i] <= lim)
            mat[a[i]][b[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= lim)
        {
            int t = a[i] * a[i] - b[i];
            if (1 <= t && t <= n)
                ans += mat[a[i]][t];
        }
    }
    for (int i = 2; i <= lim; i += 2)
        ans -= mat[i][i * i / 2];
    ans /= 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= min(lim, a[i] - 1) && j * a[i] <= 2 * n; j++)
        {
            int t = a[i] * j - b[i];
            if (1 <= t && t <= n)
                ans += mat[j][t];
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}