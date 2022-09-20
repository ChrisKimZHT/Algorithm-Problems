#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20;
char mat[MAXN][MAXN];
bool vis[MAXN][MAXN];
int t;
int n, m, k;

int main()
{
    cin >> t;
    while (t--)
    {
        memset(vis, false, sizeof(vis));
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++)
            cin >> mat[i];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == '*')
                {
                    int size = 0;
                    for (int t = 1;; t++)
                    {
                        if (i - t < 0 || j - t < 0 || j + t >= m)
                            break;
                        if (mat[i - t][j - t] != '*' || mat[i - t][j + t] != '*')
                            break;
                        size++;
                    }
                    if (size >= k)
                        for (int t = 0; t <= size; t++)
                            vis[i - t][j + t] = vis[i - t][j - t] = true;
                }
            }
        }
        bool flag = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (mat[i][j] == '*' && !vis[i][j])
                {
                    flag = false;
                    break;
                }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}