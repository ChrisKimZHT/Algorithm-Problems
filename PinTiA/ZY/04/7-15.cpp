#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int m, n;
	cin >> m >> n;
	int mat[6][6];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][(j + m) % n];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}