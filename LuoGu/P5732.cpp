#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n, mat[20][20]{1};
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		mat[i][0] = 1;
		for (int j = 1; j < i; j++)
		{
			mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j];
		}
		mat[i][i] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}