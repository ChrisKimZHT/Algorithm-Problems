#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

const int MAXN = 1e6 + 10;
int cnt[MAXN];

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (cnt[a[i]] - 1) * (cnt[a[i]] - 2);
        for (int j = 2; a[i] * j * j < MAXN; j++)
            ans += cnt[a[i] * j] * cnt[a[i] * j * j];
    }
    cout << ans << endl;
    for (int i = 0; i < n; ++i)
        cnt[a[i]]--;
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