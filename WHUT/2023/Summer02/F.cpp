#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

int n, l, r;
int now = 0, ans = 0;

int cnt(int x)
{
    int pow = 0;
    while (x)
    {
        pow++;
        x /= 2;
    }
    int res = 1;
    for (int i = 1; i < pow; i++)
        res *= 2;
    return res - 1;
}

void calc(int x)
{
    int sub = cnt(x);
    int delta = ans;
    if (x >= 2)
    {
        if (now + sub < l || now + 1 > r)
            now += sub;
        else
            calc(x / 2);
    }
    delta = ans - delta;
    now++;
    if (l <= now && now <= r)
        ans += x % 2;
    if (l <= now - sub && now + sub <= r)
    {
        ans += delta;
        now += sub;
        return;
    }
    if (x >= 2)
    {
        if (now + sub < l || now + 1 > r)
            now += sub;
        else
            calc(x / 2);
    }
}

void solve()
{
    cin >> n >> l >> r;
    calc(n);
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}