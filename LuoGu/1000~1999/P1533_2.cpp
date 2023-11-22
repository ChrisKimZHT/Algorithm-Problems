#include <bits/stdc++.h>

using namespace std;

struct NUM
{
	char a[20], b[20];
	int alength = 0, blength = 0;
	int type = 0; // 0为整数，1为小数，2为分数，3为百分数
};

int main(void)
{
	char tmp;
	bool flag = false;
	NUM n;
	while (cin >> tmp)
	{
		if (tmp == '.')
		{
			n.type = 1;
			flag = true;
			continue;
		}
		else if (tmp == '/')
		{
			n.type = 2;
			flag = true;
			continue;
		}
		else if (tmp == '%')
		{
			n.type = 3;
			continue;
		}
		if (flag)
		{
			n.b[n.blength++] = tmp;
		}
		else
		{
			n.a[n.alength++] = tmp;
		}
	}
	if (n.type == 0)
	{
		if (n.a[0] == '0')
			cout << '0';
		else
		{
			bool head = false;
			for (int i = n.alength - 1; i >= 0; i--)
			{
				if (n.a[i] != '0')
				{
					head = true;
				}
				if (head)
				{
					cout << n.a[i];
				}
			}
		}
	}
	else if (n.type == 1)
	{
		if (n.a[0] == '0')
			cout << '0';
		else
		{
			bool head = false;
			for (int i = n.alength - 1; i >= 0; i--)
			{
				if (n.a[i] != '0')
				{
					head = true;
				}
				if (head)
				{
					cout << n.a[i];
				}
			}
		}
		cout << '.';
		bool head = false;
		bool zero = true;
		int zeropos = 0;
		for (int i = 0; i < n.blength; i++)
		{
			if (n.b[i] != '0')
				zero = false;
			if (zero)
				zeropos++;
		}
		if (zero)
		{
			cout << '0';
		}
		else
		{
			for (int i = n.blength - 1; i >= zeropos; i--)
			{
				if (n.b[i] != '0')
				{
					head = true;
				}
				if (head)
				{
					cout << n.b[i];
				}
			}
		}
	}
	else if (n.type == 2)
	{
		if (n.a[0] == '0')
			cout << '0';
		else
		{
			bool head = false;
			for (int i = n.alength - 1; i >= 0; i--)
			{
				if (n.a[i] != '0')
				{
					head = true;
				}
				if (head)
				{
					cout << n.a[i];
				}
			}
		}
		cout << '/';
		bool head = false;
		for (int i = n.blength - 1; i >= 0; i--)
		{
			if (n.b[i] != '0')
			{
				head = true;
			}
			if (head)
			{
				cout << n.b[i];
			}
		}
	}
	else if (n.type == 3)
	{
		if (n.a[0] == '0')
			cout << '0';
		else
		{
			bool head = false;
			for (int i = n.alength - 1; i >= 0; i--)
			{
				if (n.a[i] != '0')
				{
					head = true;
				}
				if (head)
				{
					cout << n.a[i];
				}
			}
		}
		cout << '%';
	}
	return 0;
}