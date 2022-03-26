#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	bool mat[120][120]{};
	int n, m, k;
	cin >> n >> m >> k;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		x += 4;
		y += 4;
		mat[x - 2][y] = mat[x - 1][y] = mat[x + 1][y] = mat[x + 2][y] = mat[x][y] = mat[x][y - 1] = mat[x][y - 2] = mat[x][y + 1] = mat[x][y + 2] = mat[x - 1][y - 1] = mat[x + 1][y - 1] = mat[x - 1][y + 1] = mat[x + 1][y + 1] = true;
	}
	while (k--)
	{
		int x, y;
		cin >> x >> y;
		x += 4;
		y += 4;
		for (int i = -2; i <= 2; i++)
		{
			for (int j = -2; j <= 2; j++)
			{
				mat[x + i][y + j] = true;
			}
		}
	}
	int count = 0;
	for (int i = 5; i < n + 5; i++)
	{
		for (int j = 5; j < n + 5; j++)
		{
			if (!mat[i][j])
			{
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}