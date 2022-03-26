#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n, m;
	double maxscore = 0;
	cin >> n >> m;
	while (n--)
	{
		int maxi = 0, mini = INT32_MAX;
		int sum = 0;
		for (int i = 0; i < m; i++)
		{
			int tmp;
			cin >> tmp;
			sum += tmp;
			maxi = max(maxi, tmp);
			mini = min(mini, tmp);
		}
		sum -= maxi + mini;
		maxscore = max(maxscore, 1.0 * sum / (m - 2));
	}
	printf("%.2lf", maxscore);
	return 0;
}