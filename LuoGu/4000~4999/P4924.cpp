#include <bits/stdc++.h>

using namespace std;

const int MAXN = 550;
int n, m;
int mat[MAXN][MAXN];
int tmp[MAXN][MAXN];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = i * n + j + 1;
    while (m--)
    {
        int x, y, r, z;
        cin >> x >> y >> r >> z;
        x--;
        y--;
        memcpy(tmp, mat, sizeof(mat));
        for (int i = -r; i <= r; i++)
        {
            for (int j = -r; j <= r; j++)
            {
                if (z)
                    mat[x + i][y + j] = tmp[x + j][y - i];
                else
                    mat[x + i][y + j] = tmp[x - j][y + i];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << ' ';
        cout << endl;
    }
    return 0;
}