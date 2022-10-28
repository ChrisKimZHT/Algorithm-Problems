#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a[0];
    int g = a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        g = __gcd(g, a[i]);
    }
    if (g == 1)
        cout << 0 << endl;
    else if (__gcd(g, n) == 1)
        cout << 1 << endl;
    else if (__gcd(g, n - 1) == 1)
        cout << 2 << endl;
    else
        cout << 3 << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}