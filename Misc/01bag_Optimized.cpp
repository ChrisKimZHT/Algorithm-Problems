#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 1010;
int N, V;             // N-物品数量 V-背包容积
int v[SIZE], w[SIZE]; // v-体积 w-价值
int dp[SIZE];         // 一维动态规划

int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= N; i++)
        for (int j = V; j >= v[i]; j--)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    cout << dp[V] << endl;
    return 0;
}