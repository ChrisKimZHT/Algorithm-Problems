#include <iostream>
#include <cctype>
#include <cstdio>

using namespace std;

int main(void)
{
	int N, letter = 0, blank = 0, digit = 0, other = 0;
	cin >> N;
	getchar();
	char a;
	while (N--)
	{
		scanf("%c", &a);
		if (isalpha(a))
		{
			letter++;
		}
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
	cout << "letter = " << letter << ", blank = " << blank << ", digit = " << digit << ", other = " << other;
	return 0;
}