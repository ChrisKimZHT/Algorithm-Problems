#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30;
long long dp[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dx[9] = {0, -1, -1, -2, -2, 2, 2, 1, 1};
int dy[9] = {0, -2, 2, -1, 1, -1, 1, -2, 2};

int main()
{
    int x, y, m, n;
    cin >> x >> y >> m >> n;
    x += 2;
    y += 2;
    m += 2;
    n += 2;
    for (int i = 0; i < 9; i++)
        vis[m + dx[i]][n + dy[i]] = true;
    dp[1][2] = 1;
    for (int i = 2; i <= x; i++)
        for (int j = 2; j <= y; j++)
            if (!vis[i][j])
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    cout << dp[x][y] << endl;
    return 0;
}