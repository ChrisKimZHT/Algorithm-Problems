#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
int n, t;
int mat[MAXN][MAXN];
int fa[2 * MAXN];
inline void init()
{
    for (int i = 1; i <= 2 * n; i++)
        fa[i] = i;
}
int find(int x)
{
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // cin >> t;
    scanf("%d", &t);
    while (t--)
    {
        // cin >> n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                // cin >> mat[i][j];
                scanf("%d", &mat[i][j]);
        init();
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                int fi = find(i), fj = find(j);
                int fin = find(i + n), fjn = find(j + n);
                if (mat[i][j] > mat[j][i] && fi != fj)
                {
                    fa[fin] = find(fj);
                    fa[fi] = find(fjn);
                }
                else if (mat[i][j] < mat[j][i] && fin != fj)
                {
                    fa[fi] = fj;
                    fa[fin] = fjn;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (find(i) > n)
                continue;
            for (int j = 1; j <= n; j++)
                swap(mat[i][j], mat[j][i]);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                // cout << mat[i][j] << ' ';
                printf("%d ", mat[i][j]);
            // cout << endl;
            printf("\n");
        }
    }
    return 0;
}