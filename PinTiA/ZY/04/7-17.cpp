#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	char c;
	int cnt = 0;
	while ((c = getchar()) != '\n')
	{
		if (c != 'A' &&
			c != 'E' &&
			c != 'I' &&
			c != 'O' &&
			c != 'U' &&
			// isupper(c) == true)
			c >= 'A' && c <= 'Z')
		{
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}