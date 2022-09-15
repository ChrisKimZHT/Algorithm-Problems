#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	char var, value;
	int a = 0, b = 0, c = 0;
	while (~scanf("%c:=%c", &var, &value))
	{
		if (var == 'a')
		{
			if (isdigit(value))
			{
				a = value - '0';
			}
			else if (isalpha(value))
			{
				if (value == 'a')
					a = a;
				else if (value == 'b')
					a = b;
				else if (value == 'c')
					a = c;
			}
		}
		else if (var == 'b')
		{
			if (isdigit(value))
			{
				b = value - '0';
			}
			else if (isalpha(value))
			{
				if (value == 'a')
					b = a;
				else if (value == 'b')
					b = b;
				else if (value == 'c')
					b = c;
			}
		}
		else if (var == 'c')
		{
			if (isdigit(value))
			{
				c = value - '0';
			}
			else if (isalpha(value))
			{
				if (value == 'a')
					c = a;
				else if (value == 'b')
					c = b;
				else if (value == 'c')
					c = c;
			}
		}
	}
	cout << a << ' ' << b << ' ' << c;
	return 0;
}