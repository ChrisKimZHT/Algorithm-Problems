#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long ll;
const int MAXN = 55;
ll n, a[MAXN];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        a[0] *= a[i];
        a[i] = 1;
    }
    ll ans = accumulate(a, a + n, 0LL);
    cout << ans * 2022 << endl;
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
