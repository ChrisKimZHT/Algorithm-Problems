#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int cnt_2 = m / 4, cnt_1 = m / 2;
    int mn = 0, mx = 0;
    while (n--)
    {
        string s;
        cin >> s;
        int cnt_1 = 0;
        for (int i = 0; i < m; i++)
            if (s[i] == '1')
                cnt_1++;
        int two = 0;
        for (int i = 0; i < m - 1; i++)
        {
            if (s[i] == '1' && s[i + 1] == '1')
            {
                two++;
                i++;
            }
        }
        two = min(two, m / 4);
        mn += cnt_1 - two;
        two = 0;
        for (int i = 0; i < m - 1; i++)
        {
            if (s[i] != '1' || s[i + 1] != '1')
            {
                two++;
                i++;
            }
        }
        two = min(two, m / 4);
        mx += cnt_1 - (m / 4 - two);
    }
    cout << mn << ' ' << mx << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}