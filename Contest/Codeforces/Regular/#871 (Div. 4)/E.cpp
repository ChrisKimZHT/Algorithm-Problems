#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> vis(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] || a[i][j] == 0)
                continue;
            queue<pair<int, int>> que;
            vis[i][j] = true;
            que.push({i, j});
            int v = 0;
            while (que.size())
            {
                auto now = que.front();
                v += a[now.first][now.second];
                que.pop();
                for (int i = 0; i < 4; i++)
                {
                    int nx = now.first + dx[i], ny = now.second + dy[i];
                    if (0 <= nx && nx < n &&
                        0 <= ny && ny < m &&
                        !vis[nx][ny] && a[nx][ny])
                    {
                        vis[nx][ny] = true;
                        que.push({nx, ny});
                    }
                }
            }
            ans = max(ans, v);
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}