#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	char s[300], tmp;
	int length = 0;
	for (int i = 0; i < 300; i++)
	{
		s[i] = '.';
	}
	while (cin >> tmp)
	{
		s[length++] = tmp;
	}
	int boy = 0, girl = 0;
	for (int i = 0; i < length; i++)
	{
		if (s[i] == 'b' && s[i + 1] == 'o' && s[i + 2] == 'y')
		{
			s[i] = s[i + 1] = s[i + 2] = '.';
			boy++;
		}
	}
	for (int i = 0; i < length; i++)
	{
		if (s[i] == 'b' && s[i + 1] == 'o' ||
			s[i] == 'o' && s[i + 1] == 'y')
		{
			s[i] = s[i + 1] = '.';
			boy++;
		}
	}
	for (int i = 0; i < length; i++)
	{
		if (s[i] == 'g' && s[i + 1] == 'i' && s[i + 2] == 'r' && s[i + 3] == 'l')
		{
			s[i] = s[i + 1] = s[i + 2] = s[i + 3] = '.';
			girl++;
		}
	}
	for (int i = 0; i < length; i++)
	{
		if (s[i] == 'g' && s[i + 1] == 'i' && s[i + 2] == 'r' ||
			s[i] == 'i' && s[i + 1] == 'r' && s[i + 2] == 'l')
		{
			s[i] = s[i + 1] = s[i + 2] = '.';
			girl++;
		}
	}
	for (int i = 0; i < length; i++)
	{
		if (s[i] == 'g' && s[i + 1] == 'i' ||
			s[i] == 'i' && s[i + 1] == 'r' ||
			s[i] == 'r' && s[i + 1] == 'l')
		{
			s[i] = s[i + 1] = '.';
			girl++;
		}
	}
	for (int i = 0; i < length; i++)
	{
		if (s[i] == 'g' || s[i] == 'i' || s[i] == 'r' || s[i] == 'l')
		{
			girl++;
		}
		else if (s[i] == 'b' || s[i] == 'o' || s[i] == 'y')
		{
			boy++;
		}
	}
	cout << boy << endl
		 << girl << endl;
	return 0;
}