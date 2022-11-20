#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int N;
    cin >> N;
    vector<int> a(N + 2), pre(N + 2), las(N + 2);
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = N; i >= 1; i--)
    {
        las[i] = las[i + 1] + a[i];
    }
    int ans = 0;
    for (int i = 1; i < N; i++)
    {
        ans = max(ans, 114 * pre[i] + 514 * las[i + 1]);
    }
    cout << max(0LL, ans) << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}