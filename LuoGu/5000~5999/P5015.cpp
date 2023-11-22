#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	char a;
	int count = 0;
	while (cin >> a)
	{
		if (isblank(a) == 0)
		{
			count++;
		}
	}
	cout << count << endl;
	return 0;
}