#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	char num[30];
	int length = 0;
	char tmp;
	bool _int = true, _float = false, _fraction = false, _percentage = false;
	while (cin >> tmp)
	{
		num[length++] = tmp;
		if (tmp == '.')
		{
			_int = false;
			_float = true;
		}
		else if (tmp == '/')
		{
			_int = false;
			_fraction = true;
		}
		else if (tmp == '%')
		{
			_int = false;
			_percentage = true;
		}
	}
	if (_int)
	{
		bool head = true;
		if (num[0] == '0')
		{
			cout << '0';
		}
		else
		{
			for (int i = length - 1; i >= 0; i--)
			{
				if (head && num[i] == '0')
				{
					continue;
				}
				else
				{
					head = false;
					cout << num[i];
				}
			}
		}
	}
	else if (_float)
	{
		int i, dotp, tailp;
		bool dot = false, zero = true;
		bool head = true;
		for (i = length - 1; i >= 0; i--)
		{
			if (num[i] == '.')
			{
				dot = true;
				dotp = i;
				continue;
			}
			if (dot)
			{
				if (num[0] == '0')
				{
					cout << '0';
				}
				else if (head && num[i] == '0')
				{
					continue;
				}

				else
				{
					head = false;
					cout << num[i];
				}
			}
			else
			{
				if (num[i] != '0')
				{
					zero = false;
				}
			}
		}
		cout << '.';
		head = true;
		for (int i = dotp + 1; i < length; i++)
		{
			if (num[i] != '0')
			{
				tailp = i;
				break;
			}
		}
		if (zero)
		{
			cout << '0';
		}
		else
		{
			for (i = length - 1; i >= tailp; i--)
			{
				cout << num[i];
			}
		}
	}
	else if (_fraction)
	{
		int i;
		bool slash = false;
		bool head = true;
		for (i = length - 1; i >= 0; i--)
		{
			if (num[i] == '/')
			{
				slash = true;
				continue;
			}
			if (slash)
			{
				if (num[0] == '0')
				{
					cout << '0';
				}
				else if (head && num[i] == '0')
				{
					continue;
				}
				else
				{
					head = false;
					cout << num[i];
				}
			}
		}
		cout << '/';
		head = true;
		for (i = length - 1; i >= 0; i--)
		{
			if (num[i] == '/')
				break;
			if (head && num[i] == '0')
			{
				continue;
			}
			else
			{
				head = false;
				cout << num[i];
			}
		}
	}
	else if (_percentage)
	{
		bool head = true;
		if (num[0] == '0')
		{
			cout << "0%";
		}
		else
		{
			for (int i = length - 2; i >= 0; i--)
			{
				if (head && num[i] == '0')
				{
					continue;
				}
				else
				{
					head = false;
					cout << num[i];
				}
			}
			cout << '%';
		}
	}
	cout << endl;
	return 0;
}