#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int now = 0;
    int sorted = -1, nsorted = -1;
    for (int i = 0; i < s.size(); i++)
    {
        char &c = s[i];
        if (c == '+')
        {
            now++;
        }
        else if (c == '-')
        {
            now--;
            sorted = min(sorted, now);
            if (now < nsorted)
            	nsorted = -1;
        }
        else if (c == '1')
        {
            sorted = max(sorted, now);
        }
        else // if (c == '0')
        {
            if (now <= 1)
            {
                cout << "NO" << endl;
                return;
            }
            if (nsorted == -1)
                nsorted = now;
            nsorted = min(nsorted, now);
        }
        if (nsorted != -1 && nsorted <= sorted)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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