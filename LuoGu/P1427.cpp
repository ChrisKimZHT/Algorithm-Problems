#include <iostream>

using namespace std;

int main(void)
{
	int num[110], i;
	for (i = 0; i < 100; i++)
	{
		cin >> num[i];
		if (num[i] == 0)
		{
			break;
		}
	}
	for (int j = i - 1; j >= 0; j--)
	{
		cout << num[j] << ' ';
	}
	return 0;
}