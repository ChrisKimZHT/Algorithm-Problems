#include <bits/stdc++.h>
#define SIZE 700000
#define MOD 20010905
using namespace std;

long long dp[SIZE][10];
char str[SIZE];

int main(void)
{
	scanf("%s", str + 1);
	for (int i = 1; str[i] != '\0'; i++)
	{
		dp[i][1] = (dp[i - 1][1] + (str[i] == 'I' || str[i] == 'i')) % MOD;
		dp[i][2] = (dp[i - 1][2] + (str[i] == 'l' || str[i] == 'L') * dp[i - 1][1]) % MOD;
		dp[i][3] = (dp[i - 1][3] + (str[i] == 'o' || str[i] == 'O') * dp[i - 1][2]) % MOD;
		dp[i][4] = (dp[i - 1][4] + (str[i] == 'v' || str[i] == 'V') * dp[i - 1][3]) % MOD;
		dp[i][5] = (dp[i - 1][5] + (str[i] == 'e' || str[i] == 'E') * dp[i - 1][4]) % MOD;
		dp[i][6] = (dp[i - 1][6] + (str[i] == 'y' || str[i] == 'Y') * dp[i - 1][5]) % MOD;
		dp[i][7] = (dp[i - 1][7] + (str[i] == 'o' || str[i] == 'O') * dp[i - 1][6]) % MOD;
		dp[i][8] = (dp[i - 1][8] + (str[i] == 'u' || str[i] == 'U') * dp[i - 1][7]) % MOD;
	}
	cout << dp[strlen(str + 1)][8] << endl;
	return 0;
}