#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int MAXN = 2e5 + 10;
int n;
int a[MAXN], cnt_prexor[MAXN * 2];

void solve()
{
    memset(cnt_prexor, 0, sizeof(cnt_prexor));
    cnt_prexor[0] = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cnt_odd = 0, cur_xor = 0;
    for (int i = 0; i < n; i++)
    {
        cur_xor ^= a[i];
        for (int j = 0; j * j < 2 * n; j++)
        {
            int l_prexor = cur_xor ^ (j * j);
            if (l_prexor < 2 * n)
                cnt_odd += cnt_prexor[l_prexor];
        }
        cnt_prexor[cur_xor]++;
    }
    int ans = (n + 1) * n / 2 - cnt_odd;
    cout << ans << endl;
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