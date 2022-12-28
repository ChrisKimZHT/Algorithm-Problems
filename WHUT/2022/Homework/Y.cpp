#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long ll;

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    for (int i = 0; i < min(n, m); i++)
    {
        ll a = n - i, b = m - i;
        ans += a * b;
    }
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