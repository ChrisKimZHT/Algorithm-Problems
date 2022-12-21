#include <iostream>
#define endl '\n'

using namespace std;

const int MAXT = 1010, MAXW = 40;
int T, W;
int a[MAXT];
int dp[MAXT][MAXW];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T >> W;
    for (int i = 1; i <= T; i++)
    {
        int t;
        cin >> t;
        a[i] = t - 1;
    }
    for (int i = 1; i <= T; i++)
    {
        for (int j = 0; j <= min(W, i - 1); j++)
        {
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + ((a[i] == j % 2) ? 1 : 0));
            dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + ((a[i] == j % 2) ? 0 : 1));
        }
    }
    int ans = 0;
    for (int i = 0; i <= W; i++)
        ans = max(ans, dp[T][i]);
    cout << ans << endl;
    return 0;
}
