#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0, c = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'A')
            a++;
        else if (s[i] == 'C')
            c += a;
        else if (s[i] == 'M')
            ans += c;
    }
    cout << ans << endl;
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