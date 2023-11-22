#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
long long dp[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i / 2; j++)
        {
            dp[i] += dp[j];
        }
        dp[i]++;
    }
    cout << dp[n] << endl;
    return 0;
}