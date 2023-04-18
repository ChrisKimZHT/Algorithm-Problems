#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int get_dir(int dir_x, int dir_y)
{
    return (dir_x > 0 ? 1 : 0) * 2 + (dir_y > 0 ? 1 : 0);
}

void solve()
{
    int n, m, i1, j1, i2, j2;
    string d;
    cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> d;
    if (i1 == i2 && j1 == j2)
    {
        cout << 0 << endl;
        return;
    }
    vector<vector<vector<bool>>>
        vis(n + 10, vector<vector<bool>>(m + 10, vector<bool>(4)));
    int cnt = 0, dir_y = (d[1] == 'R' ? 1 : -1), dir_x = (d[0] == 'D' ? 1 : -1);
    int now_x = i1, now_y = j1;
    vis[i1][j1][get_dir(dir_x, dir_y)] = true;
    while (true)
    {
        int nxt_x = now_x + dir_x, nxt_y = now_y + dir_y;
        bool bounce = false;
        if (nxt_x > n)
        {
            nxt_x = n - 1;
            dir_x = -1;
            bounce = true;
        }
        else if (nxt_x <= 0)
        {
            nxt_x = 2;
            dir_x = 1;
            bounce = true;
        }
        if (nxt_y > m)
        {
            nxt_y = m - 1;
            dir_y = -1;
            bounce = true;
        }
        else if (nxt_y <= 0)
        {
            nxt_y = 2;
            dir_y = 1;
            bounce = true;
        }
        if (bounce)
            cnt++;
        // cout << cnt << ':' << nxt_x << ' ' << nxt_y << endl;
        if (nxt_x == i2 && nxt_y == j2)
        {
            cout << cnt << endl;
            return;
        }
        if (vis[nxt_x][nxt_y][get_dir(dir_x, dir_y)])
        {
            cout << "-1" << endl;
            return;
        }
        vis[nxt_x][nxt_y][get_dir(dir_x, dir_y)] = true;
        now_x = nxt_x;
        now_y = nxt_y;
    }
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