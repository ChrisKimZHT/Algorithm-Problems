#include <bits/stdc++.h>

using namespace std;

int N;
int Ax, Ay, Bx, By;
bool board[1510][1510];
int dist[1510][1510][4];
bool vis[1510][1510][4];
pair<int, int> dir[4] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
deque<array<int, 3>> dque;

int bfs()
{
    dist[Ax][Ay][0] = dist[Ax][Ay][1] = dist[Ax][Ay][2] = dist[Ax][Ay][3] = 0;
    vis[Ax][Ay][0] = vis[Ax][Ay][1] = vis[Ax][Ay][2] = vis[Ax][Ay][3] = true;
    for (int i = 0; i < 4; i++)
    {
        int nxt_x = Ax + dir[i].first;
        int nxt_y = Ay + dir[i].second;
        if (nxt_x < 1 || nxt_x > N || nxt_y < 1 || nxt_y > N || board[nxt_x][nxt_y])
            continue;
        dist[nxt_x][nxt_y][i] = 1;
        dque.push_front({nxt_x, nxt_y, i});
    }
    while (!dque.empty())
    {
        auto cur = dque.front();
        dque.pop_front();
        if (cur[0] == Bx && cur[1] == By)
            return dist[cur[0]][cur[1]][cur[2]];
        if (vis[cur[0]][cur[1]][cur[2]])
            continue;
        vis[cur[0]][cur[1]][cur[2]] = true;
        for (int i = 0; i < 4; i++)
        {
            int nxt_x = cur[0] + dir[i].first;
            int nxt_y = cur[1] + dir[i].second;
            if (nxt_x < 1 || nxt_x > N || nxt_y < 1 || nxt_y > N || board[nxt_x][nxt_y])
                continue;
            int tmp = dist[cur[0]][cur[1]][cur[2]];
            if (cur[2] != i)
                tmp++;
            if (tmp < dist[nxt_x][nxt_y][i])
            {
                dist[nxt_x][nxt_y][i] = tmp;
                if (cur[2] == i)
                    dque.push_front({nxt_x, nxt_y, i});
                else
                    dque.push_back({nxt_x, nxt_y, i});
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
            if (row[j] == '#')
                board[i][j + 1] = true;
        }
    }
    cout << bfs() << endl;
    return 0;
}