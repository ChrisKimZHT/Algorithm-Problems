#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> ans;
    while (n > 1)
    {
        if ((n / 2) % 2 == 1)
        {
            ans.push_back(2);
            n = n / 2;
        }
        else
        {
            ans.push_back(1);
            n = n / 2 + 1;
        }
    }
    cout << ans.size() << endl;
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