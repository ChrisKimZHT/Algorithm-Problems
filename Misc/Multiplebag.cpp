#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 1010;
int N, V;
int v[SIZE], w[SIZE], s[SIZE];
int dp[SIZE];

int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
        cin >> v[i] >> w[i] >> s[i];
    for (int i = 1; i <= N; i++)
        for (int j = V; j >= v[i]; j--)
            for (int k = 0; k * v[i] <= j && k <= s[i]; k++)
                dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);
    cout << dp[V] << endl;
    return 0;
}