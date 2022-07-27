#include <bits/stdc++.h>

using namespace std;

const int SIZE = 110;
int N, V;
int v[SIZE][SIZE], w[SIZE][SIZE], S[SIZE];
int dp[SIZE];

int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
    {
        cin >> S[i];
        for (int j = 0; j < S[i]; j++)
            cin >> v[i][j] >> w[i][j];
    }
    for (int i = 0; i <= N; i++)
        for (int j = V; j >= 0; j--)
            for (int k = 0; k < S[i]; k++)
                if (v[i][k] <= j)
                    dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k]);
    cout << dp[V] << endl;
    return 0;
}