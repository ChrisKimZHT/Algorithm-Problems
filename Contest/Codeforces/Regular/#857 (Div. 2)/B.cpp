#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int unknown = 0, known = 0;
    bool flag = false;
    int nmax = 0;
    while (n--)
    {
        int b;
        cin >> b;
        if (b == 1)
        {
            unknown++;
        }
        else
        {
            known += unknown;
            unknown = 0;
        }
        int need = unknown;
        if (known)
            need += 1 + known / 2;
        nmax = max(nmax, need);
    }
    cout << nmax << endl;
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