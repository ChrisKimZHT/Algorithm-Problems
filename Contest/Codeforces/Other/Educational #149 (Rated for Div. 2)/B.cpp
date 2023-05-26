#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 1, b = 1, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '<')
        {
            a++;
            b = 1;
        }
        else
        {
            b++;
            a = 1;
        }
        ans = max({ans, a, b});
    }
    cout << ans << endl;
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