#include <bits/stdc++.h>

using namespace std;

int mat[40][40];

int main(void)
{
	int N;
	cin >> N;
	pair<int, int> pos = make_pair(1, (1 + N) / 2);
	int num = 1;
	while (num <= N * N)
	{
		mat[pos.first][pos.second] = num++;
		if (pos.first == 1 && pos.second != N)
		{
			pos.first = N;
			pos.second++;
		}
		else if (pos.second == N && pos.first != 1)
		{
			pos.second = 1;
			pos.first--;
		}
		else if (pos.first == 1 && pos.second == N)
		{
			pos.first++;
		}
		else if (pos.first != 1 && pos.second != N)
		{
			if (!mat[pos.first - 1][pos.second + 1])
			{
				pos.first--;
				pos.second++;
			}
			else
			{
				pos.first++;
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}