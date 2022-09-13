#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 1e6;
int S[MAXSIZE];

int main(void)
{
	int length = 1;
	char tmp;
	while ((tmp = getchar()) != EOF)
	{
		if (tmp == '0')
		{
			S[length++] = -1;
		}
		else
		{
			S[length++] = 1;
		}
	}

	return 0;
}