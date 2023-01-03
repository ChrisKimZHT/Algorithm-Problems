#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int MAXN = 2e5 + 10;
int n, m;
int a[MAXN], ps[MAXN];

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        ps[i] = ps[i - 1] + a[i];
    int psm = ps[m], cnt = 0, offset = 0;
    for (int i = m - 1; i >= 1; i--)
    {
        if (ps[i] < psm + offset)
        {
            cnt++;
            offset -= a[i + 1] * 2;
        }
    }
    offset = 0;
    for (int i = m + 1; i <= n; i++)
    {
        if (ps[i] + offset < psm)
        {
            cnt++;
            offset -= a[i] * 2;
        }
    }
    cout << cnt << endl;
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