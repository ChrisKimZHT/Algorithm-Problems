#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int N, M, T;
char mat[2][MAXN][MAXN];
bool vis[2][MAXN][MAXN];
struct Pos
{
    int x, y, z;
    int l;
};

int bfs()
{
    queue<Pos> que;
    que.push({0, 0, 0, 0});
    while (!que.empty())
    {
        int x = que.front().x, y = que.front().y, z = que.front().z, l = que.front().l;
        que.pop();
        if (mat[z][x][y] == 'P')
        {
            return l;
        }
        if (mat[z][x][y] == '#')
        {
            if (!vis[!z][x][y] && mat[!z][x][y] != '*')
            {
                vis[!z][x][y] = true;
                que.push({x, y, !z, l});
            }
            continue;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i], nz = z;
            if (0 <= nx && nx < N && 0 <= ny && ny < M &&
                mat[nz][nx][ny] != '*' && !vis[nz][nx][ny])
            {
                vis[nz][nx][ny] = true;
                que.push({nx, ny, nz, l + 1});
            }
        }
    }
    return INT32_MAX;
}

void solve()
{
    memset(vis, false, sizeof(vis));
    cin >> N >> M >> T;
    for (int i = 0; i < N; i++)
        cin >> mat[0][i];
    for (int i = 0; i < N; i++)
        cin >> mat[1][i];
    int ans = bfs();
    if (ans <= T)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}