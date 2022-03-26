#include <bits/stdc++.h>

using namespace std;

int cow(int);

int main(void)
{
	int n;
	while (1)
	{
		cin >> n;
		if (!n)
			break;
		cout << cow(n) << endl;
	}
	return 0;
}

int cow(int year)
{
	if (year <= 1)
		return 1;
	else
		return cow(year - 1) + cow(year - 3);
}