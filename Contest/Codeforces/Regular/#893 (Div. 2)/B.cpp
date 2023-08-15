#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> s(m + 10);
    s[0] = 1;
    for (int i = 1; i <= m; i++)
        cin >> s[i];
    int eat = 0;
    for (int i = 1; i <= m; i++)
    {
        int dist = s[i] - s[i - 1];
        eat += (dist + d - 1) / d;
    }
    eat += (n - s[m]) / d + 1;
    // cout << eat << endl;
    int sub = 0, cnt = 0;
    for (int i = 1; i < m; i++)
    {
        int dist_1 = s[i] - s[i - 1];
        int dist_2 = s[i + 1] - s[i];
        int dist_3 = s[i + 1] - s[i - 1];
        int ans_1 = (dist_1 + d - 1) / d;
        int ans_2 = (dist_2 + d - 1) / d;
        int ans_3 = (dist_3 + d - 1) / d;
        int delta = ans_1 + ans_2 - ans_3;
        if (delta > sub)
        {
            cnt = 1;
            sub = delta;
        }
        else if (delta == sub)
        {
            cnt++;
        }
    }
    int dist_1 = s[m] - s[m - 1];
    int dist_2 = n - s[m];
    int dist_3 = n - s[m - 1];
    int ans_1 = (dist_1 + d - 1) / d;
    int ans_2 = dist_2 / d + 1;
    int ans_3 = dist_3 / d + 1;
    int delta = ans_1 + ans_2 - ans_3;
    if (delta > sub)
    {
        cnt = 1;
        sub = delta;
    }
    else if (delta == sub)
    {
        cnt++;
    }
    cout << eat - sub << ' ' << cnt << endl;
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