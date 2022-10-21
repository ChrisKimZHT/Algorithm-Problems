#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        if (i % 2)
            cout << i << ' ';
    for (int i = n; i >= 1; i--)
        if (!(i % 2))
            cout << i << ' ';
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}