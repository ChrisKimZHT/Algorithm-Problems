#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int presum[110][110];
	int n, m;
	cin >> n >> m;
	cin >> presum[1][1];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == 1 && j == 1)
				continue;
			int tmp;
			cin >> tmp;
			presum[i][j] = presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1] + tmp;
		}
	}
	int q;
	cin >> q;
	while (q--)
	{
		int u, d, l, r;
		cin >> u >> d >> l >> r;
		cout << presum[d][r] - presum[d][l - 1] - presum[u - 1][r] + presum[u - 1][l - 1] << endl;
	}

	return 0;
}