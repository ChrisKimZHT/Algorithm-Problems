#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 1e5 + 10, LOGN = 20;
int f[LOGN][MAXN];

int query(int l, int r)
{
    int len = r - l + 1;
    int pow = 0, pow2 = 1;
    while (pow2 * 2 <= len)
    {
        pow++;
        pow2 *= 2;
    }
    return max(f[pow][l], f[pow][r - pow2 + 1]);
}

void solve()
{
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> f[0][i];
    for (int i = 1; i <= LOGN; i++)
        for (int j = 1; j <= N - (1 << i) + 1; j++)
            f[i][j] = max(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
    while (M--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
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