#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt_n = 0, cnt_z = 0, min_a = INT32_MAX, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < 0)
            cnt_n++;
        else if (a[i] == 0)
            cnt_z++;
        a[i] = abs(a[i]);
        sum += a[i];
        min_a = min(min_a, a[i]);
    }
    if (cnt_z)
        cout << sum << endl;
    else if (cnt_n % 2)
        cout << sum - 2 * min_a << endl;
    else
        cout << sum << endl;
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