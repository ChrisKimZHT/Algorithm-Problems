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
    if ((n & x) != x)
    {
        cout << -1 << endl;
        return;
    }
    ll dig = 0;
    for (int i = 59; i >= 0; i--)
    {
        if (((n ^ x) >> i) & 1)
        {
            dig = i;
            break;
        }
    }
    for (int i = dig + 1; i >= 0; i--)
    {
        if (((n & x) >> i) & 1)
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << (x | (1ll << (dig + 1))) << endl;
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