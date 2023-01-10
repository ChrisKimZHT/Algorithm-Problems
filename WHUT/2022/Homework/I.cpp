#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 1e5 + 10;
int n, m;
int a[MAXN], b[MAXN];
int din[MAXN];

int h[MAXN], e[MAXN], ne[MAXN], idx;
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int tmp_ans;
void dfs(int v, int r)
{
    tmp_ans = min(tmp_ans, max(r, b[v]) - a[v]);
    for (int i = h[v]; i != -1; i = ne[i])
    {
        dfs(e[i], max(0, max(r, b[v]) - a[v]));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    for (int i = 1; i <= n - m; i++)
    {
        int u, v;
        cin >> u >> v;
        add(v, u);
        din[u]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!din[i])
        {
            tmp_ans = INT32_MAX;
            dfs(i, 0);
            ans += tmp_ans;
        }
    }
    cout << ans << endl;
    return 0;
}