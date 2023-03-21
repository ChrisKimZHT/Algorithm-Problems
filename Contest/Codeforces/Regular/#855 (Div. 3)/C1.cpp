#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    priority_queue<int> pque;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (t)
        {
            pque.push(t);
        }
        else if (pque.size())
        {
            ans += pque.top();
            pque.pop();
        }
    }
    cout << ans << endl;
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