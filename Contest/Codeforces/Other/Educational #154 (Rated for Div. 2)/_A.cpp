#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

bool check(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

void solve()
{
    string n;
    cin >> n;
    for (int i = 0; i < (1 << 9); i++)
    {
        int num = 0;
        for (int j = 0; j < 9; j++)
            if (i >> j & 1)
                num = num * 10 + n[j] - '0';
        if (num < 10)
            continue;
        if (check(num))
        {
            cout << num << endl;
            return;
        }
    }
    cout << -1 << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}