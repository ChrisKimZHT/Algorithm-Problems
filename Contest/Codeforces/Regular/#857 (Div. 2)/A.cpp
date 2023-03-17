#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int posi = 0, nega = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (t > 0)
            posi++;
        else
            nega++;
    }
    for (int i = 1; i <= posi; i++)
        cout << i << ' ';
    for (int i = posi - 1; i >= posi - nega; i--)
        cout << i << ' ';
    cout << endl;
    for (int i = 1; i <= min(posi, nega); i++)
        cout << 1 << ' ' << 0 << ' ';
    for (int i = 1; i <= posi - nega; i++)
        cout << i << ' ';
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}