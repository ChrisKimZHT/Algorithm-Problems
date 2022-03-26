#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	bool shape[10][10]{}, _shape[10][10]{}, __shape[10][10]{};
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char temp;
			cin >> temp;
			if (temp == '@')
			{
				shape[i][j] = true;
			}
			else if (temp == '-')
			{
				shape[i][j] = false;
			}
			__shape[i][n - 1 - j] = shape[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char temp;
			cin >> temp;
			if (temp == '@')
			{
				_shape[i][j] = true;
			}
			else if (temp == '-')
			{
				_shape[i][j] = false;
			}
		}
	}
	bool w1, w2, w3, w4, w5, w6;
	w1 = w2 = w3 = w4 = w5 = w6 = true;
	bool w51, w52, w53;
	w51 = w52 = w53 = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (shape[i][j] != _shape[j][n - 1 - i])
				w1 = false;
			if (shape[i][j] != _shape[n - 1 - i][n - 1 - j])
				w2 = false;
			if (shape[i][j] != _shape[n - 1 - j][i])
				w3 = false;
			if (shape[i][j] != _shape[i][n - 1 - j])
				w4 = false;
			if (__shape[i][j] != _shape[j][n - 1 - i])
				w51 = false;
			if (__shape[i][j] != _shape[n - 1 - i][n - 1 - j])
				w52 = false;
			if (__shape[i][j] != _shape[n - 1 - j][i])
				w53 = false;
			if (shape[i][j] != _shape[i][j])
				w6 = false;
		}
	}
	if (!(w51 || w52 || w53))
		w5 = false;
	if (w1)
	{
		cout << 1;
	}
	else if (w2)
	{
		cout << 2;
	}
	else if (w3)
	{
		cout << 3;
	}
	else if (w4)
	{
		cout << 4;
	}
	else if (w5)
	{
		cout << 5;
	}
	else if (w6)
	{
		cout << 6;
	}
	else
	{
		cout << 7;
	}
	return 0;
}