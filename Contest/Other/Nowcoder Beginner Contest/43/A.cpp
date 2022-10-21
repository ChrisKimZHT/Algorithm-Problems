#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int ans[1000];
	ans[0] = 0;
	for (int i = 1; i <= 1000; i++)
	{
		int x[1000], pos = 1;
		for (int j = 1; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				x[pos++] = j;
				if (i / j != j)
					x[pos++] = i / j;
			}
		}
		pos--;
		sort(x + 1, x + pos + 1);
		if (x[pos] % x[(pos + 1) / 2] == 0)
		{
			ans[i] = ans[i - 1] + 1;
		}
		else
		{
			ans[i] = ans[i - 1];
		}
	}
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		cout << ans[n] << endl;
	}
	return 0;
}