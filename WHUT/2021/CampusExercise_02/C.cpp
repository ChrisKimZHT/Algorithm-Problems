#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	bool dot[10];
	string input;
	while (cin >> input)
	{
		memset(dot, 0, sizeof(dot));
		int _input[30];
		for (int i = 0; i < input.length(); i++)
		{
			_input[i] = input[i] - '0';
		}
		dot[_input[0]] = true;
		bool flag = true;
		for (int i = 1; i < input.length(); i++)
		{
			if (!dot[_input[i]])
			{
				dot[_input[i]] = true;
				if ((_input[i] == 1 || _input[i] == 4 || _input[i] == 7) && _input[i - 1] == _input[i] + 2 && !dot[_input[i] + 1])
				{
					flag = false;
					break;
				}
				if ((_input[i] == 3 || _input[i] == 6 || _input[i] == 9) && _input[i - 1] == _input[i] - 2 && !dot[_input[i] - 1])
				{
					flag = false;
					break;
				}
				if ((_input[i] == 1 || _input[i] == 2 || _input[i] == 3) && _input[i - 1] == _input[i] + 6 && !dot[_input[i] + 3])
				{
					flag = false;
					break;
				}
				if ((_input[i] == 7 || _input[i] == 8 || _input[i] == 9) && _input[i - 1] == _input[i] - 6 && !dot[_input[i] - 3])
				{
					flag = false;
					break;
				}
				if ((_input[i] == 1 && _input[i - 1] == 9 ||
					 _input[i] == 9 && _input[i - 1] == 1 ||
					 _input[i] == 3 && _input[i - 1] == 7 ||
					 _input[i] == 7 && _input[i - 1] == 3) &&
					!dot[5])
				{
					flag = false;
					break;
				}
			}
			else
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}