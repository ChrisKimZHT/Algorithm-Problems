#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 210, INF = 0x3f3f3f3f;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int n, m;
bool mat[MAXN][MAXN];
int dist_y[MAXN][MAXN], dist_m[MAXN][MAXN];
pair<int, int> py, pm;
vector<pair<int, int>> pk;

void bfs_y()
{
    queue<pair<int, int>> que;
    dist_y[py.first][py.second] = 0;
    que.push(py);
    while (!que.empty())
    {
        int x = que.front().first, y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (0 <= nx && nx < n &&
                0 <= ny && ny < m &&
                mat[nx][ny] && dist_y[nx][ny] == INF)
            {
                dist_y[nx][ny] = dist_y[x][y] + 1;
                que.push({nx, ny});
            }
        }
    }
}

void bfs_m()
{
    queue<pair<int, int>> que;
    dist_m[pm.first][pm.second] = 0;
    que.push(pm);
    while (!que.empty())
    {
        int x = que.front().first, y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (0 <= nx && nx < n &&
                0 <= ny && ny < m &&
                mat[nx][ny] && dist_m[nx][ny] == INF)
            {
                dist_m[nx][ny] = dist_m[x][y] + 1;
                que.push({nx, ny});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> m)
    {
        memset(mat, true, sizeof(mat));
        memset(dist_y, 0x3f, sizeof(dist_y));
        memset(dist_m, 0x3f, sizeof(dist_m));
        pk.clear();
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
            {
                if (s[j] == '#')
                    mat[i][j] = false;
                else if (s[j] == 'Y')
                    py = {i, j};
                else if (s[j] == 'M')
                    pm = {i, j};
                else if (s[j] == '@')
                    pk.push_back({i, j});
            }
        }
        bfs_y();
        bfs_m();
        int ans = INT32_MAX;
        for (auto &p : pk)
            ans = min(ans, dist_m[p.first][p.second] + dist_y[p.first][p.second]);
        cout << ans * 11 << endl;
    }
    return 0;
}