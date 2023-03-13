#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        int l = 1, r = i + 1;
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            if (a[i - mid + 1] >= mid)
                l = mid;
            else
                r = mid - 1;
        }
        cout << l << ' ';
    }
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