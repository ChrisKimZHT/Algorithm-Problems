#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

struct Rec
{
    int a, b, c, d;
    int l, w;
};

void solve()
{
    Rec r1, r2, r3;
    cin >> r1.a >> r1.b >> r1.c >> r1.d;
    cin >> r2.a >> r2.b >> r2.c >> r2.d;
    cin >> r3.a >> r3.b >> r3.c >> r3.d;
    int ans = 0;
    // + r1
    ans += (r1.c - r1.a) * (r1.d - r1.b);
    // + r2
    ans += (r2.c - r2.a) * (r2.d - r2.b);
    // + r3
    ans += (r3.c - r3.a) * (r3.d - r3.b);
    // - r1 & r2
    ans -= max((min({r1.c, r2.c}) - max({r1.a, r2.a})), 0LL) * max(min({r1.d, r2.d}) - max({r1.b, r2.b}), 0LL);
    // - r1 & r3
    ans -= max(min({r1.c, r3.c}) - max({r1.a, r3.a}), 0LL) * max(min({r1.d, r3.d}) - max({r1.b, r3.b}), 0LL);
    // - r2 & r3
    ans -= max(min({r2.c, r3.c}) - max({r2.a, r3.a}), 0LL) * max(min({r2.d, r3.d}) - max({r2.b, r3.b}), 0LL);
    // + r1 & r2 & r3
    ans += max(min({r1.c, r2.c, r3.c}) - max({r1.a, r2.a, r3.a}), 0LL) * max(min({r1.d, r2.d, r3.d}) - max({r1.b, r2.b, r3.b}), 0LL);
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}