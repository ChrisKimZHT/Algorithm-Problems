#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    ll base = 4, base_ans = 26;
    ll ans = base_ans + (base + 1 + n) * (n - base) + n - base;
    cout << ans << endl;
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