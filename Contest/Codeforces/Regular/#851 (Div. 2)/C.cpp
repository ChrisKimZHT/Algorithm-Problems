#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n % 2)
    {
        cout << "YES" << endl;
        int r = 2 * n;
        for (int i = 1; i <= n; i += 2)
            cout << i << ' ' << r-- << endl;
        for (int i = 2; i <= n; i += 2)
            cout << i << ' ' << r-- << endl;
    }
    else
    {
        cout << "NO" << endl;
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