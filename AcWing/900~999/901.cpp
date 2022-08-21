#include <bits/stdc++.h>

using namespace std;

const int MAXN = 310;
int mat[MAXN][MAXN];
int dis[MAXN][MAXN];
int R, C;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int dfs(int x, int y)
{
    if (dis[x][y])
        return dis[x][y];
    dis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (1 <= nx && nx <= R &&
            1 <= ny && ny <= C &&
            mat[nx][ny] > mat[x][y])
            dis[x][y] = max(dis[x][y], dfs(nx, ny) + 1);
    }
    return dis[x][y];
}

int main()
{
    cin >> R >> C;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            cin >> mat[i][j];
    int ans = 0;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            ans = max(ans, dfs(i, j));
    cout << ans << endl;
    return 0;
}