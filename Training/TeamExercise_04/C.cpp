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
		long long ans = 1;
		if (n >= k)
		{
			for (int j = 0; j < k; j++)
			{
				ans *= (n - j);
			}
			for (int p = 2; p <= k; p++)
			{
				ans /= p;
			}
			for (int j = 0; j < k; j++)
			{
				ans *= (n - j);
			}
		}
		else
		{
			ans = 0;
		}
		cout << "Case " << i << ": " << ans << endl;
	}
	return 0;
}