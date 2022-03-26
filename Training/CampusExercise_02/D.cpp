#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		char str[100010];
		scanf("%s", str);
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == '0' || str[i] == '2' || str[i] == '4' || str[i] == '6' || str[i] == '9')
			{
				cout << str[i];
			}
			else if (str[i] == 'z' && str[i + 1] == 'e' && str[i + 2] == 'r' && str[i + 3] == 'o')
			{
				cout << "0";
			}
			else if (str[i] == 't' && str[i + 1] == 'w' && str[i + 2] == 'o')
			{
				cout << "2";
			}
			else if (str[i] == 'f' && str[i + 1] == 'o' && str[i + 2] == 'u' && str[i + 3] == 'r')
			{
				cout << "4";
			}
			else if (str[i] == 's' && str[i + 1] == 'i' && str[i + 2] == 'x')
			{
				cout << "6";
			}
			else if (str[i] == 'n' && str[i + 1] == 'i' && str[i + 2] == 'n' && str[i + 3] == 'e')
			{
				cout << "9";
			}
		}
		cout << endl;
	}
	return 0;
}