#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int mat1[10][10], mat2[10][10];
	char t;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> t;
			mat1[i][j] = t;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> t;
			mat2[i][j] = t;
		}
	}
	bool flag1 = true, flag2 = true, flag3 = true, flag4 = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (mat1[i][j] != mat2[j][N - i - 1])
			{
				flag1 = false;
			}
			if (mat1[i][j] != mat2[N - j - 1][i])
			{
				flag2 = false;
			}
			if (mat1[i][j] != mat2[N - i - 1][N - j - 1])
			{
				flag3 = false;
			}
			if (mat1[i][j] != mat2[i][j])
			{
				flag4 = false;
			}
		}
	}
	if (flag1)
		cout << "1" << endl;
	else if (flag2)
		cout << "2" << endl;
	else if (flag3)
		cout << "3" << endl;
	else if (flag4)
		cout << "4" << endl;
	else
		cout << "5" << endl;
	return 0;
}