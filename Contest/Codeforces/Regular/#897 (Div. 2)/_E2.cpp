#include <bits/stdc++.h>
// #define endl '\n'
// #define int long long

using namespace std;

int query(int x)
{
    cout << "? " << x << endl;
    int res;
    cin >> res;
    return res;
}

void finish(int x)
{
    cout << "! " << x << endl;
    return;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    // remain length: [n, 2 * n)
    for (int i = 1; i + k - 1 <= n - k; i += k)
        ans ^= query(i);
    if (n % k)
    {
        int offset = (n / k - 1) * k;
        int len = n - offset;
        int pre = (len - k) / 2;
        ans ^= query(offset + 1 + pre);
        ans ^= query(offset + 1);
        query(offset + 1);
        query(offset + 1 + pre);
    }
    ans ^= query(n - k + 1);
    finish(ans);
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}