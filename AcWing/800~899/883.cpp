#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;
const double EPS = 1e-6;
int n;
double mat[MAXN][MAXN];

int gauss()
{
    int row, col;
    for (row = 0, col = 0; col < n; col++)
    {
        int max_row = row;
        for (int i = row; i < n; i++)
            if (fabs(mat[i][col]) > fabs(mat[max_row][col]))
                max_row = i;
        if (fabs(mat[max_row][col]) < EPS)
            continue;
        for (int i = col; i <= n; i++)
            swap(mat[max_row][i], mat[row][i]);
        for (int i = n; i >= col; i--)
            mat[row][i] /= mat[row][col];
        for (int i = row + 1; i < n; i++)
            if (fabs(mat[i][col]) > EPS)
                for (int j = n; j >= col; j--)
                    mat[i][j] -= mat[i][col] * mat[row][j];
        row++;
    }
    if (row < n)
    {
        for (int i = row; i < n; i++)
            if (fabs(mat[i][n]) > EPS)
                return 2;
        return 1;
    }
    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            mat[i][n] -= mat[i][j] * mat[j][n];
    return 0;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            cin >> mat[i][j];
    int t = gauss();
    if (t == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (fabs(mat[i][n]) < EPS)
                cout << 0.00 << endl;
            else
                cout << fixed << setprecision(2) << mat[i][n] << endl;
        }
    }
    else if (t == 1)
    {
        cout << "Infinite group solutions" << endl;
    }
    else // if (t == 2)
    {
        cout << "No solution" << endl;
    }
    return 0;
}