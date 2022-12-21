#include <iostream>
#include <cstring>
#define endl '\n'

using namespace std;

const int MAXN = 110, MAXM = 100100;
int n, m;
int a[MAXN], c[MAXN];
bool dp[MAXM];
int cnt[MAXM], ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> m, n || m)
    {
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        ans = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> c[i];
        for (int i = 0; i < n; i++)
        {
            memset(cnt, 0, sizeof(cnt));
            for (int j = a[i]; j <= m; j++)
            {
                if (!dp[j] && dp[j - a[i]] && cnt[j - a[i]] < c[i])
                {
                    dp[j] = true;
                    cnt[j] = cnt[j - a[i]] + 1;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}