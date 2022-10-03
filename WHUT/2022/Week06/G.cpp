#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10, MAXM = 2e5 + 10;
int u[MAXM], v[MAXM], w[MAXM];
int fa[MAXN * 2], sz[MAXN * 2];
int n, m;
int find(int a)
{
    return fa[a] == a ? a : (fa[a] = find(fa[a]));
}
long long p2[31];
void init_p2()
{
    p2[0] = 1;
    for (int i = 1; i <= 30; i++)
        p2[i] = p2[i - 1] * 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init_p2();
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> u[i] >> v[i] >> w[i];
    long long ans = 0;
    for (int i = 0; i < 30; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            fa[j] = j;
            fa[j + n] = j + n;
            sz[j] = 1;
            sz[j + n] = 0;
        }
        for (int j = 0; j < m; j++)
        {
            int fu = find(u[j]), fv = find(v[j]);
            int fun = find(u[j] + n), fvn = find(v[j] + n);
            if (w[j] >> i & 1)
            {
                if (fu == fv)
                {
                    cout << -1 << endl;
                    return 0;
                }
                if (fun == fv)
                    continue;
                sz[fv] += sz[fun];
                sz[fu] += sz[fvn];
                fa[fun] = fv;
                fa[fvn] = fu;
            }
            else
            {
                if (fun == fv)
                {
                    cout << -1 << endl;
                    return 0;
                }
                if (fu == fv)
                    continue;
                sz[fv] += sz[fu];
                sz[fvn] += sz[fun];
                fa[fu] = fv;
                fa[fun] = fvn;
            }
        }
        for (int j = 1; j <= n; j++)
        {
            ans += p2[i] * min(sz[find(j)], sz[find(j + n)]);
            sz[find(j)] = sz[find(j + n)] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}