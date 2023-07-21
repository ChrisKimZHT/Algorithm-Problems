#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

char ans[1005][1005];
void solve()
{
    int n, m;
    cin >> n >> m;
    int x1 = 0, x2 = 0;
    for (int i = 1; i <= n; i++)
    {
        char t1, t2;
        if (i & 1)
        {
            t1 = 'x';
            t2 = 'o';
        }
        else
        {
            t1 = 'o';
            t2 = 'x';
        }
        for (int j = 1; j <= m; j++)
        {
            if (((j + 1) / 2) & 1)
            {
                ans[i][j] = t1;
            }
            else
                ans[i][j] = t2;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            if (ans[i][j] == 'x')
                x1++;
            else
                x2++;
        }
    }
    // cout<<x1<<" "<<x2<<"\n";
    if (x1 - x2 == 2)
    {
        ans[1][1] = 'o';
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << ans[i][j];
        }
        cout << "\n";
    }
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