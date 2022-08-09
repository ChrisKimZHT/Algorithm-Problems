#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30;
bool col[MAXN], dig[MAXN], sdig[MAXN];
int tr[MAXN];
char ans[MAXN][MAXN];
int n;

void init()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                ans[i][j] = 'Q';
            else
                ans[i][j] = '.';
}

void dfs(int x)
{
    if (x > n)
    {
        for (int i = 1; i <= n; i++)
            printf("%s\n", ans[tr[i] - 1]);
        printf("\n");
    }
    for (int i = 1; i <= n; i++)
    {
        if (!col[i] && !dig[x + i - 1] && !sdig[n - x + i])
        {
            col[i] = true;
            dig[x + i - 1] = true;
            sdig[n - x + i] = true;
            tr[x] = i;
            dfs(x + 1);
            col[i] = false;
            dig[x + i - 1] = false;
            sdig[n - x + i] = false;
        }
    }
}

int main()
{
    scanf("%d", &n);
    init();
    dfs(1);
    return 0;
}