#include <iostream>
#include <cctype>
#include <cstdio>

using namespace std;

int main(void)
{
	int letter = 0, blank = 0, digit = 0, other = 0;
	char a;
	while (1)
	{
		scanf("%c", &a);
		if (a == '\n')
			break;
		// if (isalpha(a))
		// {
		// 	letter++;
		// }
		else if (isdigit(a))
		{
			digit++;
		}
		else if (isspace(a))
		{
			blank++;
		}
		else
		{
			other++;
		}
	}
	cout << "blank = " << blank << ", digit = " << digit << ", other = " << other;
	return 0;
}