#include <bits/stdc++.h>

using namespace std;

int n, length[8], choice[8];
bool flag[8];
double ans = 0;

void dfs(int x)
{
	if (x == n)
	{
		int a = 0, b = 0, c = 0;
		for (int i = 0; i < n; i++)
		{
			if (choice[i] == 0)
			{
				continue;
			}
			else if (choice[i] == 1)
			{
				a += length[i];
			}
			else if (choice[i] == 2)
			{
				b += length[i];
			}
			else if (choice[i] == 3)
			{
				c += length[i];
			}
		}
		double p = 1.0 * (a + b + c) / 2;
		double spow2 = p * (p - a) * (p - b) * (p - c);
		if (spow2 > 0)
			ans = max(ans, sqrt(spow2));
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!flag[x])
		{
			flag[x] = true;
			choice[x] = i;
			dfs(x + 1);
			flag[x] = false;
		}
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> length[i];
	}
	dfs(0);
	if (ans != 0)
		printf("%.1lf\n", ans);
	else
		printf("-1\n");
	return 0;
}