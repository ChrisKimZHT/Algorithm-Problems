#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
int n, m, q;
int dfmat[MAXN][MAXN];

void insert(int x1, int y1, int x2, int y2, int num)
{
    dfmat[x1][y1] += num;
    dfmat[x2 + 1][y1] -= num;
    dfmat[x1][y2 + 1] -= num;
    dfmat[x2 + 1][y2 + 1] += num;
}

int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int t;
            cin >> t;
            insert(i, j, i, j, t);
        }
    while (q--)
    {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dfmat[i][j] += dfmat[i - 1][j] + dfmat[i][j - 1] - dfmat[i - 1][j - 1];
            cout << dfmat[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}