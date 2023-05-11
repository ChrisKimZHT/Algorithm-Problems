#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

const int MAXN = 4e6 + 100, MAXM = 2e3 + 10;
int ans[MAXN], mat[MAXM][MAXM], now = 1;

void init()
{
    for (int i = 1; i < MAXM; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int a = i - j, b = 1 + j;
            mat[a][b] = mat[a][b - 1] + mat[a - 1][b] - mat[a - 1][b - 1] + now * now;
            ans[now] = mat[a][b];
            now++;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    cout << ans[n] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}