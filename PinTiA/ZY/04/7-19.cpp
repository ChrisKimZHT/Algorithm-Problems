#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	char c;
	cin >> c;
	getchar();
	char str;
	int pos = 0, index = -1;
	while ((str = getchar()) != '\n')
	{
		if (str == c)
			index = pos;
		pos++;
	}
	if (index != -1)
		cout << "index = " << index << endl;
	else
		cout << "Not Found" << endl;
	return 0;
}