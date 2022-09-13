#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int k;
	cin >> k;
	int c1 = 0, c5 = 0, c10 = 0;
	for (int i = 0; i < k; i++)
	{
		int t;
		cin >> t;
		if (t == 1)
			c1++;
		else if (t == 5)
			c5++;
		else if (t == 10)
			c10++;
	}
	cout << c1 << endl
		 << c5 << endl
		 << c10 << endl;
	return 0;
}