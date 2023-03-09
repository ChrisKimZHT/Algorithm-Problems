#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
int fa[MAXN], cntv[MAXN], cnte[MAXN];

void init(int x)
{
    for (int i = 1; i <= x; i++)
    {
        fa[i] = i;
        cntv[i] = 1;
        cnte[i] = 0;
    }
}

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void solve()
{
    int N, M;
    cin >> N >> M;
    init(N);
    while (M--)
    {
        int u, v;
        cin >> u >> v;
        if (find(u) == find(v))
        {
            cnte[find(u)]++;
        }
        else
        {
            cntv[find(v)] += cntv[find(u)];
            cnte[find(v)] += cnte[find(u)] + 1;
            fa[find(u)] = fa[find(v)];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (cntv[find(i)] != cnte[find(i)])
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}