#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int cnt_f = 0, cnt_e = 0;
    while (a[cnt_f] == a.front())
        cnt_f++;
    while (a[n - 1 - cnt_e] == a.back())
        cnt_e++;
    if (a.front() == a.back())
        cout << cnt_f * (cnt_f - 1) << endl;
    else
        cout << cnt_f * cnt_e * 2 << endl;
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