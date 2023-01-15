#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int w, d, h;
    cin >> w >> d >> h;
    int a, b, f, g;
    cin >> a >> b >> f >> g;
    int ans = h + abs(a - f) + abs(b - g) + 2 * min({a, w - a, b, d - b, f, w - f, g, d - g});
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