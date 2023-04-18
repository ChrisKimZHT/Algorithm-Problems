#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> k(n);
    for (int i = 0; i < n; i++)
        cin >> k[i];
    vector<double> lb(m), ub(m);
    for (int i = 0; i < m; i++)
    {
        // y = kx
        // y = ax^2 + bx + c
        // ax^2 + (b - k)x + c = 0
        // delta = (b-k)^2 - 4ac < 0
        // (b-k)^2 < 4ac
        // -sqrt(4ac) < k-b < sqrt(4ac)
        // b-sqrt(4ac) < k < b+sqrt(4ac)
        int a, b, c;
        cin >> a >> b >> c;
        lb[i] = 1.0 * b - sqrt(4.0 * a * c);
        ub[i] = 1.0 * b + sqrt(4.0 * a * c);
    }
    sort(k.begin(), k.end());
    for (int i = 0; i < m; i++)
    {
        int pos = upper_bound(k.begin(), k.end(), lb[i]) - k.begin();
        if (pos < n && k[pos] < ub[i])
        {
            cout << "Yes" << endl
                 << k[pos] << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
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