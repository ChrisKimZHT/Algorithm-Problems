#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> rp(n + 10), rq(n + 10);
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        rp[t] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        rq[t] = i;
    }
    int pmin = min(rp[1], rq[1]), pmax = max(rp[1], rq[1]);
    int ans = (n - pmax) * (n - pmax + 1) / 2 +
              (pmin - 1) * pmin / 2 +
              (pmax - pmin - 1) * (pmax - pmin) / 2 + 1;
    for (int i = 2; i <= n; i++)
    {
        int mn = min(rp[i], rq[i]);
        int mx = max(rp[i], rq[i]);
        if (mn > pmax)
            ans += (mn - pmax) * pmin;
        else if (mx < pmin)
            ans += (pmin - mx) * (n - pmax + 1);
        else if (mn < pmin && mx > pmax)
            ans += (pmin - mn) * (mx - pmax);
        pmax = max(pmax, mx);
        pmin = min(pmin, mn);
        if (pmax == n && pmin == 1)
            break;
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