#include <bits/stdc++.h>

using namespace std;

int N;
int Ax, Ay, Bx, By;
bool board[1510][1510];
int dist[1510][1510];
int last_dir[1510][1510];
pair<int, int> dir[4] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
deque<pair<int, int>> dque;

int bfs()
{
    dque.push_front({Ax, Ay});
    dist[Ax][Ay] = 0;
    last_dir[Ax][Ay] = -1;
    while (!dque.empty())
    {
        auto now = dque.front();
        dque.pop_front();
        if (now.first == Bx && now.second == By)
            return dist[now.first][now.second];
        for (int i = 0; i < 4; i++)
        {
            int next_x = now.first + dir[i].first;
            int next_y = now.second + dir[i].second;
            if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= N && board[next_x][next_y])
            {
                if (i == last_dir[now.first][now.second])
                {
                    if (dist[next_x][next_y] > dist[now.first][now.second])
                    {
                        dist[next_x][next_y] = dist[now.first][now.second];
                        last_dir[next_x][next_y] = i;
                        dque.push_front({next_x, next_y});
                    }
                }
                else
                {
                    if (dist[next_x][next_y] > dist[now.first][now.second] + 1)
                    {
                        dist[next_x][next_y] = dist[now.first][now.second] + 1;
                        last_dir[next_x][next_y] = i;
                        dque.push_back({next_x, next_y});
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    memset(dist, 0x3f, sizeof(dist));
    cin >> N;
    cin >> Ax >> Ay >> Bx >> By;
    for (int i = 1; i <= N; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++)
        {
            if (row[j] == '.')
                board[i][j + 1] = true;
        }
    }
    cout << bfs() << endl;
    return 0;
}