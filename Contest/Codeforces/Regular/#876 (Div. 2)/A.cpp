#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 10), b(n + 10);
    vector<bool> st(n + 10);
    for (int i = 1; i <= n; i++)
        a[i] = b[n + 1 - i] = (i + k - 1) / k;
    int now = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > now)
        {
            now++;
            st[i] = true;
        }
    }
    now = 0;
    for (int i = n; i >= 1; i--)
    {
        if (st[i])
            now++;
        if (b[i] > now)
        {
            now++;
            st[i] = true;
        }
    }
    cout << now << endl;
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