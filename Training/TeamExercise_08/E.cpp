#include <iostream>

using namespace std;

int price[] = {10, 20, 50, 100};
int n, ans;
int dp[1010];

int main()
{
    scanf("%d", &n);
    dp[0] = 1;
    for (int i = 0; i < 4; i++)
        for (int j = price[i]; j <= n; j += 10)
            dp[j] += dp[j - price[i]];
    printf("%d\n", dp[n]);
    return 0;
}