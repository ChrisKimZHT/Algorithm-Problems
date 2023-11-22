#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
const int MAXN = 32;
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int mat[MAXN][MAXN], ans[MAXN][MAXN];
bool vis[MAXN][MAXN];
queue<PII> que;
int n;

bool bfs(int x, int y)
{
    bool flag = true;
    que.push({x, y});
    ans[x][y] = 2;
    vis[x][y] = true;
    while (que.size())
    {
        PII now = que.front();
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            PII nxt = {now.first + dx[i], now.second + dy[i]};
            if (nxt.first < 0 || nxt.first >= n ||
                nxt.second < 0 || nxt.second > n)
            {
                flag = false;
                continue;
            }
            if (!vis[nxt.first][nxt.second] &&
                !ans[nxt.first][nxt.second])
            {
                vis[nxt.first][nxt.second] = true;
                ans[nxt.first][nxt.second] = 2;
                que.push(nxt);
            }
        }
    }
    return flag;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    bool flag;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!mat[i][j] && !vis[i][j])
            {
                memcpy(ans, mat, sizeof(mat));
                flag = bfs(i, j);
                if (flag)
                    break;
            }
        }
        if (flag)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
    return 0;
}