#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1e6 + 10;
int N, K;
int fa[MAXN];
int find(int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

int main()
{
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= 3 * N; i++)
        fa[i] = i;
    int ans = 0;
    while (K--)
    {
        int D, X, Y;
        scanf("%d%d%d", &D, &X, &Y);
        if (X > N || Y > N)
        {
            ans++;
            continue;
        }
        if (D == 1)
        {
            if (find(X + N) == find(Y) || find(X) == find(Y + N))
            {
                ans++;
            }
            else
            {
                fa[find(X)] = find(Y);
                fa[find(X + N)] = find(Y + N);
                fa[find(X + 2 * N)] = find(Y + 2 * N);
            }
        }
        else
        {
            if (find(X) == find(Y) || find(Y) == find(X + N))
            {
                ans++;
            }
            else
            {
                fa[find(X)] = find(Y + N);
                fa[find(X + N)] = find(Y + 2 * N);
                fa[find(X + 2 * N)] = find(Y);
            }
        }
    }
    printf("%d", ans);
    return 0;
}