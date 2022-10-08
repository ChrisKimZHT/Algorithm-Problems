#include <bits/stdc++.h>

using namespace std;

const int MAXN = 410;
int N, M;
vector<int> dx, dy;
int mat[MAXN][MAXN];

void init_dxy()
{
    for (int i = 0; i * i <= M; i++)
    {
        int rem = M - i * i;
        int sqr = sqrt(rem);
        if (sqr * sqr == rem)
        {
            dx.push_back(i);
            dy.push_back(sqr);
            dx.push_back(-i);
            dy.push_back(sqr);
            dx.push_back(i);
            dy.push_back(-sqr);
            dx.push_back(-i);
            dy.push_back(-sqr);
        }
    }
}

queue<pair<int, int>> que;
void bfs(int x, int y)
{
    mat[x][y] = 0;
    que.push({x, y});
    while (que.size())
    {
        auto now = que.front();
        que.pop();
        for (int i = 0; i < dx.size(); i++)
        {
            int nx = now.first + dx[i], ny = now.second + dy[i];
            if (1 <= nx && nx <= N &&
                1 <= ny && ny <= N &&
                mat[nx][ny] == -1)
            {
                mat[nx][ny] = mat[now.first][now.second] + 1;
                que.push({nx, ny});
            }
        }
    }
}

int main()
{
    memset(mat, -1, sizeof(mat));
    cin >> N >> M;
    init_dxy();
    // for (auto i : dx)
    //     cout << i << ' ';
    // cout << endl;
    // for (auto i : dy)
    //     cout << i << ' ';
    // cout << endl;
    bfs(1, 1);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << mat[i][j] << ' ';
        cout << endl;
    }
    return 0;
}