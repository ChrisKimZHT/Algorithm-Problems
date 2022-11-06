#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), h(n), t(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    h[0] = a[0];
    for (int i = 1; i < n; i++)
        h[i] = __gcd(h[i - 1], a[i]);
    t[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        t[i] = __gcd(t[i + 1], a[i]);
    int ans = max(h[n - 2], t[1]);
    for (int i = 1; i < n - 1; i++)
        ans = max(ans, __gcd(h[i - 1], t[i + 1]));
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}