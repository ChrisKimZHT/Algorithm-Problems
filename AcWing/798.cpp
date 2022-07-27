#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
int n, m, q;
int mat[MAXN][MAXN], dfmat[MAXN][MAXN];

int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            dfmat[i][j] += mat[i][j];
            dfmat[i + 1][j] -= mat[i][j];
            dfmat[i][j + 1] -= mat[i][j];
            dfmat[i + 1][j + 1] += mat[i][j];
        }
    while (q--)
    {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        dfmat[x1][y1] += c;
        dfmat[x2 + 1][y1] -= c;
        dfmat[x1][y2 + 1] -= c;
        dfmat[x2 + 1][y2 + 1] += c;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dfmat[i][j] += dfmat[i - 1][j] + dfmat[i][j - 1] - dfmat[i - 1][j - 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << dfmat[i][j] << ' ';
        cout << endl;
    }
    return 0;
}