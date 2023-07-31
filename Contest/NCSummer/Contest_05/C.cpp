#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

constexpr int MAXN = 5e3 + 10;
int mat[MAXN][MAXN];

void solve()
{
    int n;
    cin >> n;
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        bool tmp = false;
        for (int j = 1; j <= n; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j])
                tmp = true;
        }
        if (!tmp)
        {
            flag = true;
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        bool tmp = false;
        for (int j = 1; j <= n; j++)
        {
            if (mat[j][i])
                tmp = true;
        }
        if (!tmp)
        {
            flag = true;
            break;
        }
    }
    cout << n - flag << endl;
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