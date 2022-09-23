#include <bits/stdc++.h>

using namespace std;

const int MAXN = 410;
const int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
typedef pair<int, int> PII;
int dist[MAXN][MAXN];
int vis[MAXN][MAXN];
int n, m, x, y;
queue<PII> que;

void bfs()
{
    memset(dist, -1, sizeof(dist));
    dist[x][y] = 0;
    vis[x][y] = true;
    que.push({x, y});
    while (que.size())
    {
        auto now = que.front();
        que.pop();
        for (int i = 0; i < 8; i++)
        {
            PII next = {now.first + dx[i], now.second + dy[i]};
            if (1 <= next.first && next.first <= n &&
                1 <= next.second && next.second <= m &&
                !vis[next.first][next.second])
            {
                dist[next.first][next.second] = dist[now.first][now.second] + 1;
                vis[next.first][next.second] = true;
                que.push(next);
            }
        }
    }
}

int main()
{
    cin >> n >> m >> x >> y;
    bfs();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << dist[i][j] << ' ';
        cout << endl;
    }
    return 0;
}