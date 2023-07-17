#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

int get(int layer, int branch)
{
    int ans = 0, now = 1;
    for (int i = 0; i <= layer; i++)
    {
        ans += now;
        now *= branch;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 2; pow(2, i) <= n; i++)
    {
        int l = 2, r = pow(n, 1.0 / i);
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            if (get(i, mid) > n)
                r = mid - 1;
            else
                l = mid;
        }
        if (get(i, l) == n)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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