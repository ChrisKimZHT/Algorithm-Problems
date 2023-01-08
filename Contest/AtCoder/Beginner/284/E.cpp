#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 2e5 + 10;
int N, M;
vector<int> edge[MAXN];
bool vis[MAXN];
int ans;

void dfs(int x)
{
    if (ans == 1e6)
        return;
    ans++;
    for (auto nx : edge[x])
    {
        if (!vis[nx])
        {
            vis[nx] = true;
            dfs(nx);
            vis[nx] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    vis[1] = true;
    dfs(1);
    cout << ans << endl;
    return 0;
}