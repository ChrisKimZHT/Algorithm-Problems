#include <bits/stdc++.h>

using namespace std;

void solve()
{
    char c;
    int n;
    cin >> c >> n;
    getchar();
    vector<vector<bool>> mat(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        for (int j = 0; j < s.size(); j++)
            if (s[j] == '@')
                mat[i][j] = true;
    }
    auto tmp = mat;
    for (int i = 0; i < n; i++)
        reverse(mat[i].begin(), mat[i].end());
    reverse(mat.begin(), mat.end());
    if (tmp == mat)
        cout << "bu yong dao le" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j])
                cout << c;
            else
                cout << ' ';
        }
        cout << endl;
    }
}

signed main()
{
    solve();
    return 0;
}