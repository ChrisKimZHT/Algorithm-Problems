#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int ans[10][10]{};
	ans[0][0] = 1;
	for (int i = 1; i < N; i++)
	{
		ans[i][0] = ans[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
		}
	}
	bool start = true;
	for (int i = 0; i < N; i++)
	{
		if (!start)
			cout << endl;
		for (int j = 0; j < N - i - 1; j++)
			cout << ' ';
		for (int j = 0; j <= i; j++)
		{
			printf("%4d", ans[i][j]);
		}
		start = false;
	}
	return 0;
}