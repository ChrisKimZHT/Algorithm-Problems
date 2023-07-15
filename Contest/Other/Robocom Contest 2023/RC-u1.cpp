#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int mat[2][3]{};
    for (int i = 0; i < n; i++)
    {
        int c, p;
        cin >> c >> p;
        mat[c][p - 1]++;
    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            cout << mat[i][j] << " \n"[j == 2];
    if (mat[0][0] != mat[1][0])
    {
        if (mat[0][0] > mat[1][0])
            cout << "The first win!" << endl;
        else
            cout << "The second win!" << endl;
        return;
    }
    if (mat[0][1] != mat[1][1])
    {
        if (mat[0][1] > mat[1][1])
            cout << "The first win!" << endl;
        else
            cout << "The second win!" << endl;
        return;
    }
    if (mat[0][2] > mat[1][2])
        cout << "The first win!" << endl;
    else
        cout << "The second win!" << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}