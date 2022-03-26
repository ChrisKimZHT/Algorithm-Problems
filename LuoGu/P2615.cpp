#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int matrix[40][40] = {0};
	int count = 1;
	int x = (N + 1) / 2, y = 1;
	matrix[x][y] = 1;
	while (1)
	{
		if (count == N * N)
			break;
		if (y == 1 && x != N)
		{
			y = N;
			x++;
			matrix[x][y] = count + 1;
			count++;
			continue;
		}
		if (x == N && y != 1)
		{
			x = 1;
			y--;
			matrix[x][y] = count + 1;
			count++;
			continue;
		}
		if (y == 1 && x == N)
		{
			y++;
			matrix[x][y] = count + 1;
			count++;
			continue;
		}
		if (y != 1 && x != N)
		{
			if (!matrix[x + 1][y - 1])
			{
				x++;
				y--;
			}
			else
			{
				y++;
			}
			matrix[x][y] = count + 1;
			count++;
			continue;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << matrix[j][i] << ' ';
		}
		cout << endl;
	}
	return 0;
}