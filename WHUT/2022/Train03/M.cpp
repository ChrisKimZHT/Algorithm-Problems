#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#define endl '\n'

using namespace std;

const int MAXN = 25;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
bool mat[MAXN][MAXN];
bool vis[MAXN][MAXN];
int W, H;
pair<int, int> st;
int cnt;

void bfs()
{
    queue<pair<int, int>> que;
    que.push(st);
    vis[st.first][st.second] = true;
    while (que.size())
    {
        int x = que.front().first, y = que.front().second;
        que.pop();
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (0 <= nx && nx < H &&
                0 <= ny && ny < W &&
                mat[nx][ny] && !vis[nx][ny])
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
    while (cin >> W >> H, W && H)
    {
        memset(mat, true, sizeof(mat));
        memset(vis, false, sizeof(vis));
        cnt = 0;
        for (int i = 0; i < H; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < W; j++)
            {
                if (s[j] == '#')
                    mat[i][j] = false;
                if (s[j] == '@')
                    st = make_pair(i, j);
            }
        }
        bfs();
        cout << cnt << endl;
    }
    return 0;
}