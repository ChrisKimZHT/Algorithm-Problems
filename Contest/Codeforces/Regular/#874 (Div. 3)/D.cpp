#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    int r = max_element(p.begin() + 1, p.end()) - p.begin();
    int l = r - 1;
    if (r == n - 1)
        l = r;
    for (; l > 0; l--)
        if (p[l - 1] < p.front())
            break;
    for (int i = r; i < n; i++)
        cout << p[i] << ' ';
    for (int i = r - 1; i >= l; i--)
        cout << p[i] << ' ';
    for (int i = 0; i < l; i++)
        cout << p[i] << ' ';
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