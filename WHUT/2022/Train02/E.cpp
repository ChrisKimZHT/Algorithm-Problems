#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int need_fact2 = n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        while (!(num % 2))
        {
            num /= 2;
            need_fact2--;
        }
    }
    int pow2 = 1, cnt2 = 0;
    while (pow2 * 2 <= n)
    {
        pow2 *= 2;
        cnt2++;
    }
    int ans = 0, sub = 0;
    while (true)
    {
        if (need_fact2 <= 0)
        {
            cout << ans << endl;
            return;
        }
        if (!cnt2)
        {
            cout << -1 << endl;
            return;
        }
        int have_cnt = n / pow2 - sub;
        sub += have_cnt;
        while (need_fact2 > 0 && have_cnt > 0)
        {
            need_fact2 -= cnt2;
            have_cnt--;
            ans++;
        }
        cnt2--;
        pow2 /= 2;
    }
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}