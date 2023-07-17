#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    char mat[3][3];
    for (int i = 0; i < 3; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] = s[j];
        }
    }
    // check hori
    for (int i = 0; i < 3; i++)
    {
        if (mat[i][0] != '.' &&
            mat[i][0] == mat[i][1] &&
            mat[i][0] == mat[i][2])
        {
            cout << char(mat[i][0]) << endl;
            return;
        }
    }
    // check vert
    for (int i = 0; i < 3; i++)
    {
        if (mat[0][i] != '.' &&
            mat[0][i] == mat[1][i] &&
            mat[0][i] == mat[2][i])
        {
            cout << char(mat[0][i]) << endl;
            return;
        }
    }
    // check dig
    if (mat[0][0] != '.' &&
        mat[0][0] == mat[1][1] &&
        mat[0][0] == mat[2][2])
    {
        cout << char(mat[0][0]) << endl;
        return;
    }
    if (mat[1][1] != '.' &&
        mat[0][2] == mat[1][1] &&
        mat[2][0] == mat[1][1])
    {
        cout << char(mat[1][1]) << endl;
        return;
    }
    // draw
    cout << "DRAW" << endl;
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