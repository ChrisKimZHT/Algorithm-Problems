#include <bits/stdc++.h>
#define LENGTH 5000

using namespace std;

int stair[5010][LENGTH + 10]{};

int main(void)
{
	int N;
	cin >> N;
	stair[1][0] = 1;
	stair[2][0] = 2;
	for (int i = 3; i <= N; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			stair[i][j] = stair[i - 1][j] + stair[i - 2][j];
		}
		for (int j = 0; j < LENGTH; j++)
		{
			if (stair[i][j] > 9)
			{
				stair[i][j + 1] += (stair[i][j] / 10);
				stair[i][j] %= 10;
			}
		}
	}
	bool head = false;
	for (int i = LENGTH - 1; i >= 0; i--)
	{
		if (stair[N][i] != 0)
			head = true;
		if (head)
			cout << stair[N][i];
	}
	if (!head)
	{
		cout << 0;
	}
	return 0;
}