#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            a[i]++;
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] % a[i - 1] == 0)
        {
            a[i]++;
            if (a[i] % a[i - 1] == 0)
                a[i - 1]++;
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
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