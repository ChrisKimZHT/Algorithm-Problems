#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;
const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
// 0 U：向上
// 1 D：向下
// 2 L：向左
// 3 R：向右
int mat[MAXN][MAXN];
bool st[MAXN][MAXN];

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == 'U')
                mat[i][j + 1] = 0;
            else if (s[j] == 'D')
                mat[i][j + 1] = 1;
            else if (s[j] == 'L')
                mat[i][j + 1] = 2;
            else if (s[j] == 'R')
                mat[i][j + 1] = 3;
        }
    }
    int cnt = 0, dir = mat[x][y];
    st[x][y] = true;
    while (1 <= x && x <= n && 1 <= y && y <= m)
    {
        x += dx[dir];
        y += dy[dir];
        if (1 <= x && x <= n && 1 <= y && y <= m)
        {
            if (!st[x][y])
            {
                st[x][y] = true;
                if (mat[x][y] != dir)
                {
                    dir = mat[x][y];
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}