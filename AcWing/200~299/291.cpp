#include <bits/stdc++.h>

using namespace std;

const int MAXN = 12;
long long dp[MAXN][1 << MAXN];
bool valid[1 << MAXN];

int main()
{
    int N, M;
    while (cin >> N >> M, N || M)
    {
        for (int i = 0; i < 1 << N; i++)
        {
            valid[i] = true;
            int cnt = 0;
            for (int j = 0; j < N; j++)
            {
                if (i >> j & 1)
                {
                    if (cnt & 1)
                        valid[i] = false;
                    cnt = 0;
                }
                else
                    cnt++;
            }
            if (cnt & 1)
                valid[i] = false;
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= M; i++)
            for (int j = 0; j < 1 << N; j++)
                for (int k = 0; k < 1 << N; k++)
                    if (!(j & k) && valid[j | k])
                        dp[i][j] += dp[i - 1][k];
        cout << dp[M][0] << endl;
    }
    return 0;
}