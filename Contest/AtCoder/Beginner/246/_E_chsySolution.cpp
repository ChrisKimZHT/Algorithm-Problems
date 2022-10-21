#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <array>
// #define int long long
#define mod 998244353
#define inf 1000000000
const int N = 1510;
using namespace std;
typedef array<int, 3> arr;
deque<arr> q;
int sx, sy, ex, ey, n;
int dx[4] = {1, -1, 1, -1};
int dy[4] = {1, -1, -1, 1};
int dis[N][N][4];
bool vis[N][N][4];

signed main()
{
    ios::sync_with_stdio(false);
    memset(dis, 0x3f, sizeof(dis));
    int n;
    cin >> n;
    cin >> sx >> sy;
    sx--, sy--;
    cin >> ex >> ey;
    ex--, ey--;
    vector<string> s;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        s.push_back(a);
    }
    for (int i = 0; i < 4; i++)
    {
        int rx = sx + dx[i];
        int ry = sy + dy[i];
        if (rx < 0 || rx >= n)
        {
            continue;
        }
        if (ry < 0 || ry >= n)
        {
            continue;
        }
        if (s[rx][ry] == '#')
        {
            continue;
        }
        dis[rx][ry][i] = 1;
        q.push_back({rx, ry, i});
    }
    while (!q.empty())
    {
        arr t = q.front();
        q.pop_front();
        if (t[0] == ex && t[1] == ey)
        {
            cout << dis[ex][ey][t[2]] << '\n';
            return 0;
        }
        int rx = t[0], ry = t[1], dir = t[2];
        if (vis[rx][ry][dir])
        {
            continue;
        }
        vis[rx][ry][dir] = true;
        for (int i = 0; i < 4; i++)
        {
            int nx = rx + dx[i];
            int ny = ry + dy[i];
            if (nx < 0 || nx >= n)
            {
                continue;
            }
            if (ny < 0 || ny >= n)
            {
                continue;
            }
            if (s[nx][ny] == '#')
            {
                continue;
            }
            int rd = dis[rx][ry][dir];
            if (i != dir)
            {
                rd++;
            }
            if (dis[nx][ny][i] > rd)
            {
                dis[nx][ny][i] = rd;
                if (i == dir)
                {
                    q.push_front({nx, ny, i});
                }
                else
                {
                    q.push_back({nx, ny, i});
                }
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}