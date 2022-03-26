#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int n, k;
		cin >> n >> k;
		int ans = 0;
		for (int j = 2; j <= n; j++)
		{
			ans += k;
			ans %= j;
		}
		cout << "Case " << i << ": " << ans + 1 << endl;
	}
	return 0;
}