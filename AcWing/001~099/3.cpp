/* #include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
int N, V;
int v[MAXN], w[MAXN];
int dp[MAXN][MAXN];

int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            for (int k = 0; j >= k * v[i]; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }
    cout << dp[N][V] << endl;
    return 0;
} */

/* #include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
int N, V;
int v[MAXN], w[MAXN];
int dp[MAXN][MAXN];

int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i])
                dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
        }
    }
    cout << dp[N][V] << endl;
    return 0;
} */

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
int N, V;
int v[MAXN], w[MAXN];
int dp[MAXN];

int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if (j >= v[i])
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[V] << endl;
    return 0;
}