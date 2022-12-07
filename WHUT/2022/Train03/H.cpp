#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 8;
bool mat[MAXN][MAXN]; // true-wall false-blank
bool vis[MAXN][MAXN];
pair<int, int> las[MAXN][MAXN]; // fir-x sec-y
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

void bfs()
{
    queue<pair<int, int>> que;
    que.push({0, 0});
    las[0][0] = {-1, -1};
    vis[0][0] = true;
    while (!que.empty())
    {
        int x = que.front().first, y = que.front().second;
        que.pop();
        if (x == 4 && y == 4)
            break;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (0 <= nx && nx < 5 &&
                0 <= ny && ny < 5 &&
                !mat[nx][ny] && !vis[nx][ny])
            {
                que.push({nx, ny});
                vis[nx][ny] = true;
                las[nx][ny] = {x, y};
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> mat[i][j];
    bfs();
    vector<pair<int, int>> ans;
    for (int x = 4, y = 4; x != -1 && y != -1;)
    {
        ans.push_back({x, y});
        auto &tmp = las[x][y];
        x = tmp.first;
        y = tmp.second;
    }
    reverse(ans.begin(), ans.end());
    for (auto &p : ans)
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    return 0;
}