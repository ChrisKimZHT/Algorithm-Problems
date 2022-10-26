#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n % 2)
        cout << n << ' ';
    for (int i = n / 2; i >= 1; i--)
        cout << i << ' ' << i + n / 2 << ' ';
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