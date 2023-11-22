#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10;
bool mat[MAXN][MAXN];
bool vis[MAXN][MAXN];
int ans = 0;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int N, M, T;
int SX, SY, FX, FY;

void dfs(int x, int y)
{
    if (x == FX && y == FY)
    {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (1 <= nx && nx <= N &&
            1 <= ny && ny <= M &&
            !vis[nx][ny] && !mat[nx][ny])
        {
            vis[nx][ny] = true;
            dfs(nx, ny);
            vis[nx][ny] = false;
        }
    }
}

int main()
{
    cin >> N >> M >> T;
    cin >> SX >> SY >> FX >> FY;
    while (T--)
    {
        int x, y;
        cin >> x >> y;
        mat[x][y] = true;
    }
    vis[SX][SY] = true;
    dfs(SX, SY);
    cout << ans << endl;
    return 0;
}