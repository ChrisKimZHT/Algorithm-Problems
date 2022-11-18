#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int m, s;
    cin >> m >> s;
    map<int, bool> mp;
    int maxm = -1;
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        mp[t] = true;
        maxm = max(maxm, t);
    }
    for (int i = 1; i <= maxm; i++)
    {
        if (!mp[i])
        {
            s -= i;
            if (s < 0)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    while (s)
    {
        s -= ++maxm;
        if (s < 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}