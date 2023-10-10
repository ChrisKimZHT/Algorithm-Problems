#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

void solve()
{
    int dx, dy;
    cin >> dx >> dy;
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    long double ans = 1e9;
    long double a = sqrt(1.0L * max(ax * ax + ay * ay, (dx - ax) * (dx - ax) + (dy - ay) * (dy - ay)));
    long double b = sqrt(1.0L * max(bx * bx + by * by, (dx - bx) * (dx - bx) + (dy - by) * (dy - by)));
    ans = min({ans, a, b});
    long double c = 0.5L * sqrt(1.0L * (ax - bx) * (ax - bx) + (ay - by) * (ay - by));
    long double d = sqrt(1.0L * max(ax * ax + ay * ay, (dx - bx) * (dx - bx) + (dy - by) * (dy - by)));
    long double e = sqrt(1.0L * max(bx * bx + by * by, (dx - ax) * (dx - ax) + (dy - ay) * (dy - ay)));
    ans = min(ans, max(min(d, e), c));
    cout << fixed << setprecision(9) << ans << endl;
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