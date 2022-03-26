#include <bits/stdc++.h>

using namespace std;

bool is_max(int, int);

int mat[20][20];

int main(void)
{
	int M, N;
	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> mat[i][j];
		}
	}
	bool exist = false;
	for (int i = 1; i < M - 1; i++)
	{
		for (int j = 1; j < N - 1; j++)
		{
			if (is_max(i, j))
			{
				exist = true;
				cout << mat[i][j] << ' ' << i + 1 << ' ' << j + 1 << endl;
			}
		}
	}
	if (!exist)
	{
		cout << "None " << M << ' ' << N << endl;
	}
	return 0;
}

bool is_max(int i, int j)
{
	if (mat[i][j] > mat[i + 1][j] &&
		mat[i][j] > mat[i - 1][j] &&
		mat[i][j] > mat[i][j + 1] &&
		mat[i][j] > mat[i][j - 1])
	{
		return true;
	}
	else
	{
		return false;
	}
}