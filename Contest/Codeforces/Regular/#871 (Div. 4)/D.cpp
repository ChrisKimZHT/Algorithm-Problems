#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

set<int> s;

void split(int x)
{
    s.insert(x);
    if (x % 3 == 0)
    {
        split(x / 3);
        split(x / 3 * 2);
    }
}

void solve()
{
    s.clear();
    int n, m;
    cin >> n >> m;
    split(n);
    if (s.count(m))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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