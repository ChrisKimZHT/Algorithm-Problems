#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<bool> pre(n + 10), suf(n + 10);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] ^ (a[i] & 1);
    for (int i = n; i >= 1; i--)
        suf[i] = suf[i + 1] ^ (a[i] & 1);
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        int len = r - l + 1;
        int range_sum = len * k;
        int other_sum = pre[l - 1] + suf[r + 1];
        if ((range_sum + other_sum) & 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
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