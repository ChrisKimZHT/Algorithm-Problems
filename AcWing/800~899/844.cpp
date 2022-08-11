#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;
bool maze[MAXN][MAXN];
int dist[MAXN][MAXN];
int n, m;
pair<int, int> que[MAXN * MAXN];
int qh = 0, qt = -1;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void bfs()
{
    que[++qt] = {0, 0};
    dist[0][0] = 0;
    while (qt - qh >= 0)
    {
        pair<int, int> now = que[qh++];
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> nxt = {now.first + dx[i], now.second + dy[i]};
            if (nxt.first >= 0 && nxt.first < n &&
                nxt.second >= 0 && nxt.second < m &&
                dist[nxt.first][nxt.second] == -1 && maze[nxt.first][nxt.second] == 0)
            {
                dist[nxt.first][nxt.second] = dist[now.first][now.second] + 1;
                que[++qt] = nxt;
            }
        }
    }
}

int main()
{
    memset(dist, -1, sizeof(dist));
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maze[i][j];
    bfs();
    cout << dist[n - 1][m - 1] << endl;
    return 0;
}