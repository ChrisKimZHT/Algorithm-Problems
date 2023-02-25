#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> cnt(n + m + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]] = m + 1;
    }
    for (int i = 1; i <= m; i++)
    {
        int p, v;
        cin >> p >> v;
        cnt[a[p]] -= m - i + 1;
        cnt[v] += m - i + 1;
        a[p] = v;
    }
    long long ans = 0;
    for (int i = 1; i <= n + m; i++)
    {
        if (cnt[i])
        {
            long long t = 1LL * cnt[i] * (cnt[i] - 1) / 2;
            t += 1LL * cnt[i] * (m + 1 - cnt[i]);
            ans += t;
        }
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