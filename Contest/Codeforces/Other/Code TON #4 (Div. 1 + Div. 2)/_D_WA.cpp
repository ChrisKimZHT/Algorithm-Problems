#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int q;
    cin >> q;
    int lb = 0, ub = INT64_MAX;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int a, b, n;
            cin >> a >> b >> n;
            int delta = a - b;
            int _lb, _ub;
            if (n == 1)
            {
                _lb = 0;
                _ub = a;
            }
            else
            {
                _lb = delta * (n - 1) + b;
                _ub = delta * n + b;
            }
            if ((lb <= _lb && _lb <= ub) ||
                (lb <= _ub && _ub <= ub))
            {
                lb = max(lb, _lb);
                ub = min(ub, _ub);
                cout << 1 << ' ';
                continue;
            }
            cout << 0 << ' ';
            continue;
        }
        else // if (op == 2)
        {
            int a, b;
            cin >> a >> b;
            int delta = a - b;
            // cout << endl
            //      << lb << ' ' << ub << endl;
            int _min = (max(0LL, lb - a + 1) + delta - 1) / delta + 1;
            if (_min * delta + b >= ub)
                cout << _min << ' ';
            else
                cout << -1 << ' ';
        }
    }
    cout << endl;
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