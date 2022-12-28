#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 15;
const int dx[] = {1, -1, 0, 0, 1, -1, 1, -1},
          dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
int mat[MAXN][MAXN];

bool check(int x, int y, int c)
{
    for (int i = 0; i < 8; i++)
    {
        int nx = x, ny = y;
        bool flag = true;
        for (int j = 0; j < 5; j++)
        {
            if (!(1 <= nx && nx <= 12 &&
                  1 <= ny && ny <= 12 &&
                  mat[nx][ny] == c))
            {
                flag = false;
                break;
            }
            nx += dx[i];
            ny += dy[i];
        }
        if (flag)
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i <= 12; i++)
        for (int j = 1; j <= 12; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= 12; i++)
    {
        for (int j = 1; j <= 12; j++)
        {
            if (mat[i][j] == 0)
            {
                mat[i][j] = 1;
                for (int ii = 1; ii <= 12; ii++)
                {
                    for (int jj = 1; jj <= 12; jj++)
                    {
                        if (check(ii, jj, 1))
                        {
                            cout << "YES" << endl;
                            return 0;
                        }
                    }
                }
                mat[i][j] = 0;
            }
            if (mat[i][j] == 0)
            {
                mat[i][j] = 2;
                for (int ii = 1; ii <= 12; ii++)
                {
                    for (int jj = 1; jj <= 12; jj++)
                    {
                        if (check(ii, jj, 2))
                        {
                            cout << "YES" << endl;
                            return 0;
                        }
                    }
                }
                mat[i][j] = 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}