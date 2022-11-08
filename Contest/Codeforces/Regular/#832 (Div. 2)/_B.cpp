#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int t = n / 2;
    cout << t + n % 2 << endl;
    for (int i = 0; i < t; i++)
        cout << i * 3 + 1 << ' ' << (n - i) * 3 << endl;
    if (n % 2)
        cout << t * 3 + 1 << ' ' << t * 3 + 3 << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}