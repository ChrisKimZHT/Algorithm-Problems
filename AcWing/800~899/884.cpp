#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;
int n;
bool mat[MAXN][MAXN];

int gauss()
{
    int row, col;
    for (row = 0, col = 0; col < n; col++)
    {
        int max_row = row;
        for (int i = row; i < n; i++)
            if (mat[i][col])
                max_row = i;
        if (!mat[max_row][col])
            continue;
        for (int i = col; i <= n; i++)
            swap(mat[max_row][i], mat[row][i]);
        for (int i = row + 1; i < n; i++)
            if (mat[i][col])
                for (int j = n; j >= col; j--)
                    mat[i][j] ^= mat[row][j];
        row++;
    }
    if (row < n)
    {
        for (int i = row; i < n; i++)
            if (mat[i][n])
                return 2;
        return 1;
    }
    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            mat[i][n] ^= mat[i][j] * mat[j][n];
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
            cout << mat[i][n] << endl;
        }
    }
    else if (t == 1)
    {
        cout << "Multiple sets of solutions" << endl;
    }
    else // if (t == 2)
    {
        cout << "No solution" << endl;
    }
    return 0;
}