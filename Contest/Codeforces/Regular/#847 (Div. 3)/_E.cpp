#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    long long x, a, b;
    cin >> x;
    a = x, b = 0;
    for (int i = 32; i >= 0; i--)
    {
        if (x >> i & 1)
            continue;
        if (x * 2 - a - b >= 1LL << (i + 1))
        {
            a += 1LL << i;
            b += 1LL << i;
        }
    }
    if (a + b == x * 2 && a ^ b == x)
        cout << a << ' ' << b << endl;
    else
        cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}