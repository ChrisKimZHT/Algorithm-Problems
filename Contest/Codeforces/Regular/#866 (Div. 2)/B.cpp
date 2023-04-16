#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int first_zero = s.find('0');
    if (first_zero == s.npos)
    {
        cout << 1LL * s.size() * s.size() << endl;
    }
    else
    {
        int len = 0, tmp = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[(i + first_zero) % s.size()] == '1')
            {
                tmp++;
            }
            else
            {
                len = max(len, tmp);
                tmp = 0;
            }
        }
        len = max(len, tmp);
        int x = (len + 1) / 2;
        cout << (len + 1 - x) * x << endl;
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