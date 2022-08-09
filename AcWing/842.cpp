#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20;
bool vis[MAXN];
int tr[MAXN];
int n;

void dfs(int x)
{
    if (x == n)
    {
        for (int i = 0; i < n; i++)
            printf("%d ", tr[i]);
        printf("\n");
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            tr[x] = i;
            dfs(x + 1);
            vis[i] = false;
        }
    }
}

int main()
{
    scanf("%d", &n);
    dfs(0);
    return 0;
}