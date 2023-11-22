#include <bits/stdc++.h>

using namespace std;

int n, cnt = 0;
int ans[32];
bool row[32], x1[32], x2[32];

void dfs(int x)
{
	if (x == n + 1)
	{
		cnt++;
		if (cnt <= 3)
		{
			for (int i = 1; i <= n; i++)
			{
				printf("%d ", ans[i]);
			}
			cout << endl;
		}
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!row[i] && !x1[n - i + x] && !x2[i + x - 1])
		{
			ans[x] = i;
			row[i] = true;
			x1[n - i + x] = true;
			x2[i + x - 1] = true;
			dfs(x + 1);
			row[i] = false;
			x1[n - i + x] = false;
			x2[i + x - 1] = false;
		}
	}
}

int main(void)
{
	cin >> n;
	dfs(1);
	cout << cnt << endl;
	return 0;
}