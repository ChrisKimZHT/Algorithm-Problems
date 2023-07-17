#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n, d, h;
    cin >> n >> d >> h;
    vector<int> pos(n);
    for (auto &ele : pos)
        cin >> ele;
    double res = 0.0;
    int last = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (last + h <= pos[i])
        {
            res += 0.5 * d * h;
        }
        else
        {
            int t = pos[i] - last;
            res += 1.0 * t * d - 0.5 * t * t / h * d;
        }
        last = pos[i];
    }
    cout << fixed << setprecision(9) << res << endl;
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