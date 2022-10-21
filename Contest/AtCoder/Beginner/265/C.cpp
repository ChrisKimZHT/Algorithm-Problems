#include <bits/stdc++.h>

using namespace std;

const int MAXN = 510;
int H, W;
char G[MAXN][MAXN];
bool vis[MAXN][MAXN];

int main()
{
    cin >> H >> W;
    for (int i = 1; i <= H; i++)
        cin >> G[i] + 1;
    int x = 1, y = 1;
    while (!vis[x][y])
    {
        if (G[x][y] == 'U')
        {
            if (x != 1)
            {
                vis[x][y] = true;
                x--;
            }
            else
                break;
        }
        else if (G[x][y] == 'D')
        {
            if (x != H)
            {
                vis[x][y] = true;
                x++;
            }
            else
                break;
        }
        else if (G[x][y] == 'L')
        {
            if (y != 1)
            {
                vis[x][y] = true;
                y--;
            }
            else
                break;
        }
        else if (G[x][y] == 'R')
        {
            if (y != W)
            {
                vis[x][y] = true;
                y++;
            }
            else
                break;
        }
    }
    if (!vis[x][y])
        cout << x << ' ' << y << endl;
    else
        cout << -1 << endl;
    return 0;
}