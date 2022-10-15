#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int cnt_0 = 0, cnt_1 = 0;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        if (t)
            cnt_1++;
        else
            cnt_0++;
    }
    if (cnt_1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}