#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	unsigned long long trinum[100000];
	for (int i = 0; i < 100000; i++)
	{
		trinum[i] = i * (i + 1) / 2;
	}
	int n;
	cin >> n;
	bool find = false;
	for (int i = 1; i < 100000; i++)
	{
		int tmp = n - trinum[i];
		if (tmp < trinum[i])
			break;
		// cout << trinum[lower_bound(trinum, trinum + 100000, tmp) - trinum] << endl;
		if (trinum[lower_bound(trinum, trinum + 100000, tmp) - trinum] == tmp)
		{
			find = true;
			break;
		}
	}
	if (find)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}