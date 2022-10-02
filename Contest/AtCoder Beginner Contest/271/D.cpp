#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110, MAXS = 10010;
int N, S;
int a[MAXN], b[MAXN];
bool dp[MAXN][MAXS];

int main()
{
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> a[i] >> b[i];
    dp[0][0] = true;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < S; j++)
            if (dp[i][j])
                dp[i + 1][j + a[i]] = dp[i + 1][j + b[i]] = true;
    if (dp[N][S])
    {
        cout << "Yes" << endl;
        int t = S;
        string ans;
        for (int i = N - 1; i >= 0; i--)
        {
            if (t - a[i] >= 0 && dp[i][t - a[i]])
            {
                t -= a[i];
                ans += "H";
            }
            else
            {
                t -= b[i];
                ans += "T";
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}