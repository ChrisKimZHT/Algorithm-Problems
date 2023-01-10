#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long ll;

void solve()
{
    ll n, x;
    cin >> n >> x;
    if (n == x)
    {
        cout << x << endl;
        return;
    }
    ll nxorx = n ^ x, nandx = n & x;
    if (nandx != x)
    {
        cout << -1 << endl;
        return;
    }
    ll cnt_digx = 0, cnt_dign = 0;
    while (n >> cnt_dign)
        cnt_dign++;
    while (x >> cnt_digx)
        cnt_digx++;
    ll max_dig = max(cnt_dign, cnt_digx), dig = 0;
    for (int i = max_dig - 1; i >= 0; i--)
    {
        if ((nxorx >> i) & 1)
        {
            dig = i;
            break;
        }
    }
    for (int i = 0; i < max_dig; i++)
    {
        if ((nandx >> i) & 1)
        {
            if (i - 1 <= dig)
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    ll ans = x | (1ll << (dig + 1));
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}