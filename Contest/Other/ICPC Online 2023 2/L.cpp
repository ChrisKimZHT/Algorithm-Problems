#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

typedef unsigned long long ull;
constexpr ull P = 449, MOD = 436522843;

void solve()
{
    string s;
    cin >> s;
    s = " " + s;
    int n = s.size() - 1;
    vector<ull> p(n + 10), h(n + 10);
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * P % MOD;
        h[i] = (h[i - 1] * P % MOD + s[i]) % MOD;
    }
    auto sub_hash = [&](int l, int r) -> ull
    {
        return (h[r] - h[l - 1] * p[r - l + 1] % MOD + MOD) % MOD;
    };
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int l = i, r = i + 1;
        int ll = l, rr = r;
        while (1 <= ll && rr <= n)
        {
            // cout << sub_hash(ll, l) << ' ' << sub_hash(r, rr) << endl;
            if (sub_hash(ll, l) == sub_hash(r, rr))
            {
                ans++;
                l = ll - 1;
                r = rr + 1;
            }
            ll--;
            rr++;
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
