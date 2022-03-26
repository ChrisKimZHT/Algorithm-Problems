#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int num, digit[20], count = 0;
	cin >> num;
	if (!num)
		cout << "0 ";
	while (num)
	{
		digit[count] = num % 10;
		count++;
		num /= 10;
	}
	for (int i = count - 1; i >= 0; i--)
	{
		cout << digit[i] << ' ';
	}
	return 0;
}