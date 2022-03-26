#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N, mat[10][10]{};
	cin >> N;
	mat[0][0] = 1;
	int cnt = 1, x = 0, y = 0;
	while (cnt < N * N)
	{
		while (x + 1 < N && mat[x + 1][y] == 0)
		{
			mat[++x][y] = ++cnt;
		}
		while (y + 1 < N && mat[x][y + 1] == 0)
		{
			mat[x][++y] = ++cnt;
		}
		while (x - 1 >= 0 && mat[x - 1][y] == 0)
		{
			mat[--x][y] = ++cnt;
		}
		while (y - 1 >= 0 && mat[x][y - 1] == 0)
		{
			mat[x][--y] = ++cnt;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%3d", mat[j][i]);
		}
		cout << endl;
	}
	return 0;
}