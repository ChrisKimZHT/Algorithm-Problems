#include <iostream>
#include <queue>
#include <cstring>
#define endl '\n'

using namespace std;

const int MAXN = 32, INF = 0x3f3f3f3f;
const int dx[] = {1, -1, 0, 0, 0, 0},
          dy[] = {0, 0, 1, -1, 0, 0},
          dz[] = {0, 0, 0, 0, 1, -1};
int L, R, C;
bool maze[MAXN][MAXN][MAXN];
int dist[MAXN][MAXN][MAXN];
struct Pos
{
    int x, y, z;
    Pos()
    {
        x = y = z = 0;
    }
    Pos(int _x, int _y, int _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
} st, ed;

void bfs()
{
    queue<Pos> que;
    que.push(st);
    dist[st.x][st.y][st.z] = 0;
    while (que.size())
    {
        int x = que.front().x, y = que.front().y, z = que.front().z;
        que.pop();
        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
            if (0 <= nx && nx < L &&
                0 <= ny && ny < R &&
                0 <= nz && nz < C &&
                maze[nx][ny][nz] &&
                dist[nx][ny][nz] == INF)
            {
                dist[nx][ny][nz] = dist[x][y][z] + 1;
                que.push(Pos(nx, ny, nz));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> L >> R >> C, L && R && C)
    {
        memset(maze, true, sizeof(maze));
        memset(dist, 0x3f, sizeof(dist));
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                string s;
                cin >> s;
                for (int k = 0; k < C; k++)
                {
                    if (s[k] == '#')
                        maze[i][j][k] = false;
                    else if (s[k] == 'S')
                        st = Pos(i, j, k);
                    else if (s[k] == 'E')
                        ed = Pos(i, j, k);
                }
            }
        }
        bfs();
        int ans = dist[ed.x][ed.y][ed.z];
        if (ans != INF)
            cout << "Escaped in " << ans << " minute(s)." << endl;
        else
            cout << "Trapped!" << endl;
    }
    return 0;
}