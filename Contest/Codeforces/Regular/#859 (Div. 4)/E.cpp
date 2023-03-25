#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll query(ll l, ll r)
{
    cout << "? " << r - l + 1 << ' ';
    for (int i = l; i <= r; i++)
        cout << i << ' ';
    cout << endl;
    ll ans;
    cin >> ans;
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 10), pre(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (query(l, mid) == pre[mid] - pre[l - 1])
            l = mid + 1;
        else
            r = mid;
    }
    cout << "! " << l << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}