#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int MAXN = 20;
int H, W;
int A[MAXN][MAXN];
int ans = 0;
set<int> s;

void dfs(int x, int y)
{
    if (x == H && y == W)
    {
        ans++;
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (1 <= nx && nx <= H &&
            1 <= ny && ny <= W &&
            !s.count(A[nx][ny]))
        {
            s.insert(A[nx][ny]);
            dfs(nx, ny);
            s.erase(A[nx][ny]);
        }
    }
}

void solve()
{
    cin >> H >> W;
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
            cin >> A[i][j];
    s.insert(A[1][1]);
    dfs(1, 1);
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}