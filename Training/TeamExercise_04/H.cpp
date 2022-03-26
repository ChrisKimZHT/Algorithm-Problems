#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		long long n;
		cin >> n;
		int ans = 0;
		for (long long j = 1; j * j <= n; j++)
		{
			ans++;
			if (j * j * 2 <= n)
				ans++;
		}
		cout << "Case " << i << ": " << n - ans << endl;
	}
	return 0;
}