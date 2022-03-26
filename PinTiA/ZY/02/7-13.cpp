#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int chara = 'A';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			printf("%c ", chara);
			chara++;
		}
		printf("\n");
	}
	return 0;
}