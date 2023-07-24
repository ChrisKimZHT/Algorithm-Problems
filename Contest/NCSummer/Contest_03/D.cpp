#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> mat(n);
    bool flag = true;
    for (int i = 0; i < n; i++)
        cin >> mat[i];
    for (int i = 1; i < n; i++)
    {
        bool same = false;
        if (mat[i][0] == mat[i - 1][0])
            same = true;
        for (int j = 0; j < n; j++)
        {
            if (same && mat[i][j] != mat[i - 1][j])
                flag = false;
            else if (!same && mat[i][j] == mat[i - 1][j])
                flag = false;
        }
    }
    if (!flag)
    {
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    int cnt_0 = 0, cnt_1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (mat[i][0] == '0')
            cnt_0++;
        else
            cnt_1++;
    }
    ans = min(cnt_0, cnt_1);
    cnt_0 = 0, cnt_1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (mat[0][i] == '0')
            cnt_0++;
        else
            cnt_1++;
    }
    ans += min(cnt_0, cnt_1);
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}