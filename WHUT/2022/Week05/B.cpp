#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m)
    {
        vector<vector<int>> mat(n + 10, vector<int>(m + 10));
        int p;
        cin >> p;
        while (p--)
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            mat[x1][y1]++;
            mat[x2 + 1][y1]--;
            mat[x1][y2 + 1]--;
            mat[x2 + 1][y2 + 1]++;
        }
        // for (int i = 0; i <= n; i++)
        // {
        //     for (int j = 0; j <= m; j++)
        //         cout << setw(3) << mat[i][j] << ' ';
        //     cout << endl;
        // }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
        // for (int i = 0; i <= n; i++)
        // {
        //     for (int j = 0; j <= m; j++)
        //         cout << setw(3) << mat[i][j] << ' ';
        //     cout << endl;
        // }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (mat[i][j])
                    mat[i][j] = mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1] + 1;
                else
                    mat[i][j] = mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
        // for (int i = 0; i <= n; i++)
        // {
        //     for (int j = 0; j <= m; j++)
        //         cout << setw(3) << mat[i][j] << ' ';
        //     cout << endl;
        // }
        int q;
        cin >> q;
        while (q--)
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int area = (x2 - x1 + 1) * (y2 - y1 + 1);
            int mcnt = mat[x2][y2] - mat[x1 - 1][y2] - mat[x2][y1 - 1] + mat[x1 - 1][y1 - 1];
            // cout << area << ':' << mcnt << endl;
            if (area == mcnt)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}