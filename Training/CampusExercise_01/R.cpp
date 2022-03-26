#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int num[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> num[i];
	}
	sort(num, num + 10);
	for (int i = 9; i >= 0; i--)
	{
		if (num[i] % 2)
		{
			cout << num[i] << ' ';
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (!(num[i] % 2))
		{
			cout << num[i] << ' ';
		}
	}
	return 0;
}