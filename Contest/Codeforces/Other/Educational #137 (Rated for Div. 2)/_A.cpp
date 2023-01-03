#include <bits/stdc++.h>

using namespace std;

inline int comb(int a)
{
    return a * (a - 1) / 2;
}

void solve()
{
    int n;
    cin >> n;
    int t;
    for (int i = 0; i < n; i++)
        cin >> t;
    cout << 6 * comb(10 - n) << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}