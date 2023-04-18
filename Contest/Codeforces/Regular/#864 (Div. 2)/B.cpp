#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    vector<vector<int>> revmat(mat);
    reverse(revmat.begin(), revmat.end());
    for (auto &ele : revmat)
        reverse(ele.begin(), ele.end());
    int diff = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] != revmat[i][j])
                diff++;
    diff /= 2;
    if (k < diff)
    {
        cout << "No" << endl;
        return;
    }
    if (n % 2)
    {
        cout << "Yes" << endl;
    }
    else
    {
        int delta = k - diff;
        if (delta % 2)
        {
            cout << "No" << endl;
            return;
        }
        cout << "Yes" << endl;
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