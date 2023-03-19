#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    double b;
    vector<double> w(n), x(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    cin >> b;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    double s = b;
    for (int i = 0; i < n; i++)
        s += w[i] * x[i];
    if (s <= 0.0)
        cout << "0.00" << endl;
    else
        cout << fixed << setprecision(2) << s << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}