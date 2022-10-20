#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10;

void solve()
{
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> x >> y;
    if (m < n)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}