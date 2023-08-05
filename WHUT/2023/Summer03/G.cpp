#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int ans = 0, last = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
            continue;
        int num = 0;
        for (int j = i; j < s.size() && j < i + 22; j++)
        {
            num = num * 2 + (s[j] - '0');
            if (num > j - last)
                break;
            ans++;
        }
        last = i;
    }
    cout << ans << endl;
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