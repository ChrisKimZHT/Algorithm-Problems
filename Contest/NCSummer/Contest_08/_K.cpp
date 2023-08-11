#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

constexpr int MAXN = 220;
vector<vector<int>> mat(MAXN, vector<int>(MAXN));
vector<vector<int>> bak(MAXN, vector<int>(MAXN));
int n, m;

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    // sort mat
    vector<pair<int, int>> fr(m + 10);
    for (int i = 1; i <= m; i++)
    {
        fr[i].first = mat[1][i];
        fr[i].second = i;
    }
    sort(fr.begin() + 1, fr.begin() + 1 + m);
    bak = mat;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            bak[i][j] = mat[i][fr[j].second];
    bool col_sorted = true;
    for (int i = 1; i <= m; i++)
        if (bak[1][i] != mat[1][i])
            col_sorted = false;
    sort(bak.begin() + 1, bak.begin() + 1 + n, [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
    // fliter illgal cases
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (bak[i][j] != (i - 1) * m + j)
            {
                cout << "NSFW" << endl;
                return;
            }
        }
    }
    // fox one step win
    if (col_sorted)
    {
        int row_diff = 0;
        for (int i = 1; i <= n; i++)
            if (mat[i][1] != (i - 1) * m + 1)
                row_diff++;
        if (row_diff == 2)
        {
            cout << "FOX" << endl;
            return;
        }
    }
    // row = 2, col = 2
    if (n == 2 && m == 2)
    {
        if (mat[1][1] == 2 || mat[1][1] == 3)
            cout << "FOX" << endl;
        else if (mat[1][1] == 4)
            cout << "CAT" << endl;
        else
            assert(0);
        return;
    }
    if (n == 2)
    {
        bool row_sorted = mat[1][1] < mat[2][1];
        int col_inv = 0;
        for (int i = 1; i <= m; i++)
            for (int j = i + 1; j <= m; j++)
                if (mat[1][i] > mat[1][j])
                    col_inv++;
        if (col_inv % 2 == !row_sorted)
            cout << "CAT" << endl;
        else
            cout << "NSFW" << endl;
        return;
    }
    if (m == 2)
    {
        col_sorted = mat[1][1] < mat[1][2];
        int row_inv = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                if (mat[i][1] > mat[j][1])
                    row_inv++;
        if (row_inv % 2 == col_sorted)
            cout << "FOX" << endl;
        else
            cout << "NSFW" << endl;
        return;
    }
    cout << "NSFW" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}