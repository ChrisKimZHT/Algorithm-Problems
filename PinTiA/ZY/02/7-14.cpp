#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < (n + 1) / 2; i++)
	{
		for (int j = 0; j < (n + 1) / 2 - i - 1; j++)
		{
			printf("  ");
		}
		for (int j = 0; j < (2 + 4 * i) / 2; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	for (int i = (n + 1) / 2 - 2; i >= 0; i--)
	{
		for (int j = 0; j < (n + 1) / 2 - i - 1; j++)
		{
			printf("  ");
		}
		for (int j = 0; j < (2 + 4 * i) / 2; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}