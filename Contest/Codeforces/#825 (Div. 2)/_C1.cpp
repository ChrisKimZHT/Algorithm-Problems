#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
int t, n;
int a[MAXN];
int dp[MAXN];

int main()
{
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = min(dp[i - 1] + 1, a[i]);
            ans += dp[i];
        }
        cout << ans << endl;
    }
    return 0;
}