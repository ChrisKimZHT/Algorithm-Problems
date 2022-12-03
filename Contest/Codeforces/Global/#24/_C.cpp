#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    if (a.front() == a.back())
    {
        cout << n / 2 << endl;
        return;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        while (j < n && a[j] == a[i])
            j++;
        ans = max(ans, (n - j) * j);
        i = j - 1;
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