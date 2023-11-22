#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

constexpr int MAXN = 1e6 + 10;
int h[MAXN], e[MAXN], ne[MAXN], idx;
int mylog2[MAXN]; // \lfloor log_{2}{x} \rfloor + 1
int fa[MAXN][30], dep[MAXN];

void init()
{
    memset(h, -1, sizeof(h));
    for (int i = 1; i < MAXN; i++)
        mylog2[i] = mylog2[i - 1] + (1 << mylog2[i - 1] == i);
}

void add(int x, int y)
{
    e[idx] = y;
    ne[idx] = h[x];
    h[x] = idx++;
}

void dfs(int now, int father)
{
    fa[now][0] = father;
    dep[now] = dep[father] + 1;
    for (int i = 0; i < mylog2[dep[now]]; i++)
        fa[now][i + 1] = fa[fa[now][i]][i];
    for (int i = h[now]; i != -1; i = ne[i])
        if (e[i] != father)
            dfs(e[i], now);
}

int lca(int a, int b)
{
    if (dep[a] < dep[b])
        swap(a, b); // make a >= b
    while (dep[a] > dep[b])
        a = fa[a][mylog2[dep[a] - dep[b]] - 1];
    if (a == b)
        return a;
    for (int i = mylog2[dep[a]] - 1; i >= 0; i--)
    {
        if (fa[a][i] != fa[b][i])
        {
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    return fa[a][0];
}

void solve()
{
    int N, M, S;
    cin >> N >> M >> S;
    for (int i = 1; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(S, 0);
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}