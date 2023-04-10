#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

map<int, int> mp{
    {6, 10000},
    {16, 72},
    {7, 36},
    {17, 180},
    {8, 720},
    {18, 119},
    {9, 360},
    {19, 36},
    {10, 80},
    {20, 306},
    {11, 252},
    {21, 1080},
    {12, 108},
    {22, 144},
    {13, 72},
    {23, 1800},
    {14, 54},
    {24, 3600},
    {15, 180},
};

int mat[4][4];
bool st[4][4];
bool show[10];

void solve()
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            int t;
            cin >> t;
            mat[i][j] = t;
            show[t] = true;
        }
    }
    int init;
    for (int i = 1; i <= 9; i++)
        if (!show[i])
            init = i;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            if (mat[i][j] == 0)
                mat[i][j] = init;
    int a, b;
    cin >> a >> b;
    cout << mat[a][b] << endl;
    cin >> a >> b;
    cout << mat[a][b] << endl;
    cin >> a >> b;
    cout << mat[a][b] << endl;
    int t;
    cin >> t;
    if (1 <= t && t <= 3)
    {
        for (int i = 1; i <= 3; i++)
            st[t][i] = true;
    }
    else if (4 <= t && t <= 6)
    {
        for (int i = 1; i <= 3; i++)
            st[i][t - 3] = true;
    }
    else if (t == 7)
    {
        st[1][1] = st[2][2] = st[3][3] = true;
    }
    else
    {
        st[1][3] = st[2][2] = st[3][1] = true;
    }
    int cnt = 0;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            if (st[i][j])
                cnt += mat[i][j];
    cout << mp[cnt] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}