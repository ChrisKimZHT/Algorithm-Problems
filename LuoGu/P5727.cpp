#include <iostream>

using namespace std;

int main(void)
{
	int num[1010], i;
	cin >> num[0];
	for (i = 1; i < 1000; i++)
	{
		if (num[i - 1] == 1)
		{
			break;
		}
		if (num[i - 1] % 2 == 0)
		{
			num[i] = num[i - 1] / 2;
		}
		else
		{
			num[i] = num[i - 1] * 3 + 1;
		}
	}
	for (int j = i - 1; j >= 0; j--)
	{
		cout << num[j] << ' ';
	}
	return 0;
}