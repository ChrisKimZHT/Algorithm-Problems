#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 10);
    deque<int> dec, inc;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int pos = 1, ans = 2;
    for (int i = 1; i <= n; i++)
    {
        while (!dec.empty() && dec.back() < a[i])
            dec.pop_back();
        while (!inc.empty() && inc.back() > a[i])
            inc.pop_back();
        dec.push_back(a[i]);
        inc.push_back(a[i]);
        while (dec.front() - inc.front() > 1)
        {
            if (a[pos] == dec.front())
                dec.pop_front();
            if (a[pos] == inc.front())
                inc.pop_front();
            pos++;
        }
        ans = max(ans, i - pos + 1);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}