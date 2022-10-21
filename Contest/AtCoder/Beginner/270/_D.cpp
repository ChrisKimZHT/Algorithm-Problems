#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int N, K, A[MAXN];
int dp[MAXN];

int main()
{
    cin >> N >> K;
    for (int i = 0; i < K; i++)
        cin >> A[i];
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            if (i < A[j])
                break;
            dp[i] = max(dp[i], i - dp[i - A[j]]);
        }
    }
    cout << dp[N] << endl;
    return 0;
}