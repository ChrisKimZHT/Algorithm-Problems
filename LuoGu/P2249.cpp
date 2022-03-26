#include <bits/stdc++.h>

using namespace std;

int num[1000010];

int main(void)
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	while (m--)
	{
		int q;
		cin >> q;
		int tmp = lower_bound(num, num + n, q) - num;
		if (num[tmp] == q)
			cout << tmp + 1 << ' ';
		else
			cout << "-1 ";
	}
	return 0;
}