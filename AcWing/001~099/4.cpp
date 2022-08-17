#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
int N, V;
int v[MAXN], w[MAXN], s[MAXN];
int dp[MAXN][MAXN];

int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
        cin >> v[i] >> w[i] >> s[i];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            for (int k = 0; k <= s[i] && k * v[i] <= j; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }
    cout << dp[N][V];
    return 0;
}