#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int n, ans = 0;
    cin >> n;
    vector<pair<int, int>> ab(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ab[i].first >> ab[i].second;
        if (ab[i].first < ab[i].second)
            swap(ab[i].first, ab[i].second);
        ans += 2 * ab[i].second;
    }
    sort(ab.begin(), ab.end());
    for (int i = n - 1; i >= 1; i--)
        ans += ab[i].first - ab[i - 1].first;
    ans += ab.front().first + ab.back().first;
    cout << ans << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}