#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (a.back() != 0)
    {
        cout << "NO" << endl;
        return;
    }
    int flag = 1;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] != flag)
            continue;
        ans.push_back(i + 1);
        flag = 1 - flag;
    }
    while (ans.size() < n)
        ans.push_back(0);
    cout << "YES" << endl;
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << ' ';
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