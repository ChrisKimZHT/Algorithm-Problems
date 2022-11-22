#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), cnt(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        cnt[i] = cnt[i + 1] + !a[i];
        if (a[i])
            ans += cnt[i];
    }
    int first_0 = 0, last_1 = n - 1;
    while (first_0 < n && a[first_0] == 1)
        first_0++;
    while (last_1 >= 0 && a[last_1] == 0)
        last_1--;
    if (cnt.front() - first_0 > (n - cnt.front()) - (n - 1 - last_1))
    {
        if (cnt.front() - first_0 - 1 > 0)
            ans += cnt.front() - first_0 - 1;
    }
    else
    {
        if ((n - cnt.front()) - (n - 1 - last_1) - 1 > 0)
            ans += ((n - cnt.front()) - (n - 1 - last_1) - 1);
    }
    cout << ans << endl;
}

signed main()
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