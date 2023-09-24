#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MAXN = 550;
int mat[MAXN][MAXN];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> mat[i][j];
    vector<bool> row(n + 10), col(n + 10);
    int ans_row = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mat[i][j] <= 0)
            {
                ans_row += mat[i][j];
                row[i] = col[j] = true;
            }
        }
    }
    int ans_col = ans_row;
    // row
    for (int i = 1; i <= n; i++)
    {
        if (!row[i])
        {
            int t = INT32_MAX;
            for (int j = 1; j <= n; j++)
                t = min(t, mat[i][j]);
            ans_row += t;
        }
    }
    // col
    for (int i = 1; i <= n; i++)
    {
        if (!col[i])
        {
            int t = INT32_MAX;
            for (int j = 1; j <= n; j++)
                t = min(t, mat[j][i]);
            ans_col += t;
        }
    }
    cout << min(ans_row, ans_col) << endl;
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
