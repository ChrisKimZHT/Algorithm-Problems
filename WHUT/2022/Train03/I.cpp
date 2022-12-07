#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 10;
int n, k, cnt;
bool mat[MAXN][MAXN];
bool st[MAXN];

void dfs(int row, int num)
{
    if (num == k)
    {
        cnt++;
        return;
    }
    if (row >= n)
    {
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (!st[col] && mat[row][col])
        {
            st[col] = true;
            dfs(row + 1, num + 1);
            st[col] = false;
        }
    }
    dfs(row + 1, num);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> k, n != -1 && k != -1)
    {
        memset(mat, false, sizeof(mat));
        memset(st, false, sizeof(st));
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++)
                if (s[j] == '#')
                    mat[i][j] = true;
        }
        dfs(0, 0);
        cout << cnt << endl;
    }
    return 0;
}