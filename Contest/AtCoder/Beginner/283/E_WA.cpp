#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 1010;
int H, W;
bool A[MAXN][MAXN];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

inline bool row_conn(int x, int y)
{
    for (int i = 0; i < 2; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (1 <= nx && nx <= H &&
            1 <= ny && ny <= W &&
            A[x][y] == A[nx][ny])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> H >> W;
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
            cin >> A[i][j];
    int ans = 0;
    bool flag = false;
    for (int i = H - 1; i >= 1; i--)
    {
        int cnt_i = 0, cnt_c = 0;
        for (int j = 1; j <= W; j++)
        {
            if (row_conn(i, j))
                cnt_c++;
            else if (A[i][j] != A[i + 1][j])
                cnt_i++;
        }
        if (cnt_i == 0)
        {
            flag = false;
            continue;
        }
        else if (cnt_c + cnt_i == W)
        {
            flag = false;
            for (int j = 1; j <= W; j++)
                A[i][j] = !A[i][j];
            ans++;
        }
        else
        {
            if (flag)
            {
                cout << -1 << endl;
                return 0;
            }
            else
            {
                flag = !flag;
            }
        }
    }
    if (flag)
        cout << -1 << endl;
    else
        cout << min(ans, H - ans) << endl;
    return 0;
}