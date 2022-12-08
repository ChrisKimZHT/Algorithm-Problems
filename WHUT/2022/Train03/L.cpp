#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#define endl '\n'

using namespace std;

const int MAXN = 110;
const int dx[] = {1, -1, 0, 0, 1, -1, 1, -1},
          dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
bool mat[MAXN][MAXN];
bool vis[MAXN][MAXN];
int m, n, cnt;

void bfs(int sx, int sy)
{
    if (vis[sx][sy] || !mat[sx][sy])
        return;
    cnt++;
    queue<pair<int, int>> que;
    que.push(make_pair(sx, sy));
    while (que.size())
    {
        int x = que.front().first, y = que.front().second;
        que.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (0 <= nx && nx < m &&
                0 <= ny && ny < n &&
                !vis[nx][ny] && mat[nx][ny])
            {
                vis[nx][ny] = true;
                que.push(make_pair(nx, ny));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> m >> n, m && n)
    {
        memset(mat, false, sizeof(mat));
        memset(vis, false, sizeof(vis));
        cnt = 0;
        for (int i = 0; i < m; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++)
                if (s[j] == '@')
                    mat[i][j] = true;
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                bfs(i, j);
        cout << cnt << endl;
    }
    return 0;
}