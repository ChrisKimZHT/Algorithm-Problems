#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

void solve()
{
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] += i + 1;
    }
    sort(a.begin(), a.end());
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum > c)
        {
            cout << i << endl;
            return;
        }
    }
    cout << n << endl;
}

signed main()
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