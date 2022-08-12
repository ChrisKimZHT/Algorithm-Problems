#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
int v[MAXN], e[MAXN], ne[MAXN], idx;
int n, ans = INT32_MAX;
bool vis[MAXN];

int dfs(int p)
{
    vis[p] = true;
    int sum = 1, maxp = 0, t = 0;
    for (int i = v[p]; i != -1; i = ne[i])
    {
        if (!vis[e[i]])
        {
            t = dfs(e[i]);
            sum += t;
            maxp = max(maxp, t);
        }
    }
    maxp = max(maxp, n - sum);
    ans = min(ans, maxp);
    return sum;
}

inline void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = v[a];
    v[a] = idx++;
}

int main()
{
    memset(v, -1, sizeof(v));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}