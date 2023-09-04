#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
            continue;
        int l = -1, r = -1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[j] == b[j] && a[j] == '1')
            {
                l = j;
                break;
            }
        }
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] == b[j] && a[j] == '1')
            {
                r = j;
                break;
            }
        }
        if (l != -1 && r != -1)
        {
            i = r;
            for (int j = l; j <= r; j++)
                a[j] = b[j] = '1';
            continue;
        }
        l = -1, r = -1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[j] == b[j] && a[j] == '0')
            {
                l = j;
                break;
            }
        }
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] == b[j] && a[j] == '0')
            {
                r = j;
                break;
            }
        }
        if (l != -1 && r != -1)
        {
            i = r;
            for (int j = l; j <= r; j++)
                a[j] = b[j] = '0';
            continue;
        }
        cout << "NO" << endl;
        return;
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