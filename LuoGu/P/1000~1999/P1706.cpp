#include <bits/stdc++.h>

using namespace std;

int n;
int ans[9], num[9];
bool flag[9];

void dfs(int x)
{
	if (x == n)
	{
		for (int i = 0; i < n; i++)
		{
			printf("%5d", ans[i]);
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!flag[i])
		{
			flag[i] = true;
			ans[x] = num[i];
			dfs(x + 1);
			flag[i] = false;
		}
	}
}

int main(void)
{
	num[0] = 1;
	num[1] = 2;
	num[2] = 3;
	num[3] = 4;
	num[4] = 5;
	num[5] = 6;
	num[6] = 7;
	num[7] = 8;
	num[8] = 9;
	cin >> n;
	dfs(0);
	return 0;
}