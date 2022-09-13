#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 33;
bool map[SIZE][SIZE];
int match[SIZE][SIZE][2];
bool vis[SIZE][SIZE];
int n, m, k;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool find(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m &&
            map[ny][nx] == false && !vis[ny][nx])
        {
            vis[ny][nx] = true;
            if (match[ny][nx][0] == 0 && match[ny][nx][1] == 0 || find(match[ny][nx][0], match[ny][nx][1]))
            {
                match[ny][nx][0] = x;
                match[ny][nx][1] = y;
                return true;
            }
        }
    }
    return false;
}

int main(void)
{
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        map[y][x] = true;
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((i + j) % 2 == 0 && map[i][j] == false)
            {
                memset(vis, false, sizeof(vis));
                if (find(j, i))
                    ans++;
            }
        }
    }
    if (k + 2 * ans == m * n)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}