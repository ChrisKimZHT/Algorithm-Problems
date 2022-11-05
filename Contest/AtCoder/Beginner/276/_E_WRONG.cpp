#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int main()
{
    int H, W;
    cin >> H >> W;
    vector<vector<bool>> C(H, vector<bool>(W));
    pair<int, int> start;
    for (int i = 0; i < H; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < W; j++)
        {
            if (row[j] == '#')
                C[i][j] = true;
            else if (row[j] == 'S')
                start = {i, j};
        }
    }
    vector<vector<int>> dep(H, vector<int>(W, -1));
    queue<pair<int, int>> que;
    dep[start.first][start.second] = 1;
    que.push(start);
    while (que.size())
    {
        auto now = que.front();
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if (0 <= nx && nx < H &&
                0 <= ny && ny < W &&
                !C[nx][ny])
            {
                if (dep[nx][ny] == -1 || dep[now.first][now.second] - dep[nx][ny] >= 2)
                {
                    que.push({nx, ny});
                    dep[nx][ny] = dep[now.first][now.second] + 1;
                    if (now.first == start.first &&
                        now.second == start.second &&
                        dep[start.first][start.second] > 2)
                    {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}