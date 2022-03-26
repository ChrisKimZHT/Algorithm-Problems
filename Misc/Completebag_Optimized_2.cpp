#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 1010;
int N, V;
int v[SIZE], w[SIZE];
int dp[SIZE];

int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= N; i++)
        for (int j = v[i]; j <= V; j++)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    cout << dp[V] << endl;
    return 0;
}