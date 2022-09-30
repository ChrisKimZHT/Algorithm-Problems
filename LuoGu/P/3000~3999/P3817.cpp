#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e5 + 10;
int n, x;
int a[MAXN];
int ans = 0;

signed main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        if (a[i - 1] + a[i] >= x)
        {
            int t = a[i - 1] + a[i] - x;
            ans += t;
            a[i] -= t;
        }
    }
    cout << ans << endl;
    return 0;
}