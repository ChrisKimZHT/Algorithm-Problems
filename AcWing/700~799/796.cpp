#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
int n, m, q;
int mat[MAXN][MAXN], psmat[MAXN][MAXN];

int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            psmat[i][j] = psmat[i - 1][j] + psmat[i][j - 1] - psmat[i - 1][j - 1] + mat[i][j];
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << psmat[x2][y2] - psmat[x1 - 1][y2] - psmat[x2][y1 - 1] + psmat[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}