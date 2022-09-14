#include <iostream>
#include <iomanip>

using namespace std;

const int MAXN = 1010;
int n, m;
int mat[MAXN][MAXN];
double aver[MAXN];

int main()
{
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        for (int i = 0; i < n; i++)
        {
            int t = 0;
            for (int j = 0; j < m; j++)
                t += mat[i][j];
            if (i)
                cout << ' ';
            cout << fixed << setprecision(2) << 1.0 * t / m;
        }
        cout << endl;
        for (int i = 0; i < m; i++)
        {
            int t = 0;
            for (int j = 0; j < n; j++)
                t += mat[j][i];
            aver[i] = 1.0 * t / n;
            if (i)
                cout << ' ';
            cout << fixed << setprecision(2) << aver[i];
        }
        cout << endl;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] < aver[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                cnt++;
        }
        cout << cnt << endl;
        cout << endl;
    }
    return 0;
}