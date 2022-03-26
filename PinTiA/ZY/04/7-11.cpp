#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int m, n;
	cin >> m >> n;
	while (m--)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int tmp;
			cin >> tmp;
			sum += tmp;
		}
		cout << sum << endl;
	}

	return 0;
}