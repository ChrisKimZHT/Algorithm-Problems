#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

int get_id(int n, int x, int y)
{
    if (x > n / 2)
        x = n - x + 1;
    if (y > n / 2)
        y = n - y + 1;
    return min(x, y);
}

void solve()
{
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    cout << abs(get_id(n, x1, y1) - get_id(n, x2, y2)) << endl;
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