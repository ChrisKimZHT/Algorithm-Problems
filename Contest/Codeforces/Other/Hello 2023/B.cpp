#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == 3)
    {
        cout << "NO" << endl;
        return;
    }
    if (n & 1)
    {
        int a = 1 - n / 2, b = n / 2;
        cout << "YES" << endl;
        for (int i = 0; i < n / 2; i++)
            cout << a << ' ' << b << ' ';
        cout << a << endl;
    }
    else
    {
        cout << "YES" << endl;
        for (int i = 0; i < n / 2; i++)
            cout << 1 << ' ' << -1 << ' ';
        cout << endl;
    }
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