#include <bits/stdc++.h>

using namespace std;

int mat[6][6];

int is_meet(int i, int j, int n)
{
	bool meet = true;
	for (int p = 0; p < n; p++)
	{
		if (mat[i][p] > mat[i][j])
			meet = false;
	}
	for (int p = 0; p < n; p++)
	{
		if (mat[p][j] < mat[i][j])
			meet = false;
	}
	return meet;
}

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
		}
	}
	bool exist = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (is_meet(i, j, n))
			{
				cout << i << ' ' << j << endl;
				exist = true;
			}
		}
	}
	if (!exist)
	{
		cout << "NONE" << endl;
	}
	return 0;
}