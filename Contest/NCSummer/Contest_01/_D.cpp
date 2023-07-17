#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1)
        cout << "Walk Alone" << endl;
    else
        cout << "Kelin" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}