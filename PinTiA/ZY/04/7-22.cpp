#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	char a[100];
	int pos = 0;
	bool isnegative = false;
	while ((a[pos] = getchar()) != '\n')
	{
		if (pos == 0 && a[pos] == '-')
			isnegative = true;
		if (a[pos] >= '0' && a[pos] <= '9' || a[pos] >= 'A' && a[pos] <= 'F' || a[pos] >= 'a' && a[pos] <= 'f')
			pos++;
	}
	pos--;
	int ans = 0;
	for (int i = 0; i <= pos; i++)
	{
		int digit;
		if (a[i] >= '0' && a[i] <= '9')
			digit = a[i] - '0';
		else if (a[i] == 'A' || a[i] == 'a')
			digit = 10;
		else if (a[i] == 'B' || a[i] == 'b')
			digit = 11;
		else if (a[i] == 'C' || a[i] == 'c')
			digit = 12;
		else if (a[i] == 'D' || a[i] == 'd')
			digit = 13;
		else if (a[i] == 'E' || a[i] == 'e')
			digit = 14;
		else if (a[i] == 'F' || a[i] == 'f')
			digit = 15;
		ans += pow(16, pos - i) * digit;
	}
	ans = isnegative ? -ans : ans;
	cout << ans;
	return 0;
}