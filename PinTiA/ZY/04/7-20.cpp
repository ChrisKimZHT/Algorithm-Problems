#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	char tmp;
	while ((tmp = getchar()) != '\n')
	{
		if (tmp >= 'A' && tmp <= 'Z')
		{
			cout << char(('A' + 'Z') / 2 + (('A' + 'Z') / 2 - tmp) + 1);
		}
		else
		{
			cout << tmp;
		}
	}
	return 0;
}