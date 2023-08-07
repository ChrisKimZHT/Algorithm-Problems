#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int t = n;
    int digit = 0;
    while (t)
    {
        digit++;
        t /= 10;
    }
    int ans = 0;
    for (int i = 1; i < digit; i++)
        ans += i * 9 * pow(10, i - 1);
    ans += (n - pow(10, digit - 1) + 1) * digit;
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}