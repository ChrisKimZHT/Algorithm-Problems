#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        if (t <= i)
            flag = true;
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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