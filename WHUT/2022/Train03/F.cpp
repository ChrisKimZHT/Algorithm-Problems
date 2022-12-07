#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 15;
const int dx[] = {1, 2, 2, 1, -1, -2, -2, -1},
          dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
int n, m, x, y;
bool vis[MAXN][MAXN];
int ans;

void dfs(int x, int y, int remain)
{
    if (remain == 0)
    {
        ans++;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= nx && nx < n &&
            0 <= ny && ny < m &&
            !vis[nx][ny])
        {
            vis[nx][ny] = true;
            dfs(nx, ny, remain - 1);
            vis[nx][ny] = false;
        }
    }
}

void solve()
{
    memset(vis, false, sizeof(vis));
    ans = 0;
    cin >> n >> m >> x >> y;
    vis[x][y] = true;
    dfs(x, y, n * m - 1);
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}