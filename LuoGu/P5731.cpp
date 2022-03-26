#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n, mat[9][9]{}, x{0}, y{0};
	mat[0][0] = 1;
	cin >> n;
	int i = 1;
	while (i < n * n)
	{
		while (x < n - 1 && mat[x + 1][y] == 0)
		{
			x++;
			i++;
			mat[x][y] = i;
		}
		while (y < n - 1 && mat[x][y + 1] == 0)
		{
			y++;
			i++;
			mat[x][y] = i;
		}
		while (x > 0 && mat[x - 1][y] == 0)
		{
			x--;
			i++;
			mat[x][y] = i;
		}
		while (y > 0 && mat[x][y - 1] == 0)
		{
			y--;
			i++;
			mat[x][y] = i;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%3d", mat[j][i]);
		}
		cout << endl;
	}
	return 0;
}