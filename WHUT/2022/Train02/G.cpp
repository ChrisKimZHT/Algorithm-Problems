#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 550;
int n;
int mat[MAXN][MAXN];

bool write(int pos)
{
    int num = mat[pos][pos], cnt = mat[pos][pos] - 1, x = pos, y = pos;
    while (cnt > 0)
    {
        bool flag = false;
        while (x - 1 >= 1 && mat[y][x - 1] == 0)
        {
            flag = true;
            mat[y][--x] = num;
            cnt--;
            if (cnt == 0)
                break;
        }
        if (cnt == 0)
            break;
        if (y + 1 <= n && mat[y + 1][x] == 0)
        {
            flag = true;
            mat[++y][x] = num;
            cnt--;
            if (cnt == 0)
                break;
        }
        else if (x + 1 <= n && mat[y][x + 1] == 0)
        {
            flag = true;
            mat[y][++x] = num;
            cnt--;
            if (cnt == 0)
                break;
        }
        if (!flag)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> mat[i][i];
    for (int i = 1; i <= n; i++)
    {
        if (!write(i))
        {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}