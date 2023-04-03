#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    double a;
    int b;
    double c;
    cin >> a >> b >> c;
    double lim = a * (b == 0 ? 2.455 : 1.26);
    cout << fixed << setprecision(2) << lim << ' ';
    if (lim > c)
        cout << "T_T" << endl;
    else
        cout << "^_^" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}