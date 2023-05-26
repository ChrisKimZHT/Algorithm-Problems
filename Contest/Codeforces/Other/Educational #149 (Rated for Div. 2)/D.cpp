#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n + 1);
    bool pos = false, neg = false;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            a[i + 1] = a[i] + 1;
        else
            a[i + 1] = a[i] - 1;
        if (a[i] > 0)
            pos = true;
        if (a[i] < 0)
            neg = true;
    }
    if (a.back() != 0)
    {
        cout << -1 << endl;
        return;
    }
    if (!(pos && neg))
    {
        cout << 1 << endl;
        for (int i = 0; i < n; i++)
            cout << 1 << ' ';
        cout << endl;
    }
    else
    {
        cout << 2 << endl;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= 0 && a[i + 1] >= 0)
                cout << 1 << ' ';
            else
                cout << 2 << ' ';
        }
        cout << endl;
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