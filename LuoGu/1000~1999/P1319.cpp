#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n, count = 0;
	bool is_one = false;
	cin >> n;
	while (1)
	{
		if (count == n * n)
			break;
		int a;
		cin >> a;
		for (int i = 0; i < a; i++)
		{
			printf("%d", is_one);
			count++;
			if (count % n == 0)
				cout << endl;
		}
		is_one = (is_one) ? false : true;
	}
	return 0;
}