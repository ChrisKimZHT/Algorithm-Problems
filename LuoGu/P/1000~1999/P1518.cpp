#include <bits/stdc++.h>

using namespace std;

vector<string> mat(10);

struct
{
    int x, y;
    int dir;
} F, C;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

inline bool valid(int x, int y)
{
    return 0 <= x && x < 10 &&
           0 <= y && y < 10 &&
           mat[x][y] == '.';
}

int main()
{
    for (int i = 0; i < 10; i++)
        cin >> mat[i];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (mat[i][j] == 'F')
            {
                F.x = i;
                F.y = j;
                F.dir = 0;
                mat[i][j] = '.';
                break;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (mat[i][j] == 'C')
            {
                C.x = i;
                C.y = j;
                C.dir = 0;
                mat[i][j] = '.';
                break;
            }
        }
    }
    for (int i = 1; i <= 1e5; i++)
    {
        if (valid(F.x + dx[F.dir], F.y + dy[F.dir]))
        {
            F.x += dx[F.dir];
            F.y += dy[F.dir];
        }
        else
        {
            F.dir = (F.dir + 1) % 4;
        }
        if (valid(C.x + dx[C.dir], C.y + dy[C.dir]))
        {
            C.x += dx[C.dir];
            C.y += dy[C.dir];
        }
        else
        {
            C.dir = (C.dir + 1) % 4;
        }
        if (F.x == C.x && F.y == C.y)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}