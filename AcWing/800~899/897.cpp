#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
int N, M;
char A[MAXN], B[MAXN];
int dp[MAXN][MAXN];

int main()
{
    cin >> N >> M;
    cin >> A + 1 >> B + 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (A[i] == B[j])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    cout << dp[N][M] << endl;
    return 0;
}