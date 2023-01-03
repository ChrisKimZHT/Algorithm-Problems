#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt_0 = 0, max_same = 1, len_same = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            cnt_0++;
        if (i && s[i] == s[i - 1])
        {
            len_same++;
        }
        else
        {
            max_same = max(max_same, len_same);
            len_same = 1;
        }
    }
    max_same = max(max_same, len_same);
    cout << max(max_same * max_same, cnt_0 * (n - cnt_0)) << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}