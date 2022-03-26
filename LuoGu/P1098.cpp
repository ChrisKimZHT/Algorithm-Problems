#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int p1, p2, p3;
	string str;
	cin >> p1 >> p2 >> p3 >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '-')
		{
			if (i == 0 || i == str.length() - 1)
			{
				cout << '-';
				continue;
			}
			if (str[i - 1] < str[i + 1] &&
				(isdigit(str[i - 1]) && isdigit(str[i + 1]) ||
				 isalpha(str[i - 1]) && isalpha(str[i + 1])))
			{
				for (char c = (p3 == 1) ? str[i - 1] + 1 : str[i + 1] - 1; (p3 == 1) ? c <= str[i + 1] - 1 : c >= str[i - 1] + 1; (p3 == 1) ? c++ : c--)
				{
					for (int k = 0; k < p2; k++)
					{
						if (p1 == 1)
						{
							cout << c;
						}
						else if (p1 == 2)
						{
							cout << (char)toupper(c);
						}
						else
						{
							cout << '*';
						}
					}
				}
			}
			else
			{
				cout << '-';
			}
		}
		else
		{
			cout << str[i];
		}
	}
	return 0;
}