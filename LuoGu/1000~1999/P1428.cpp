#include <iostream>

using namespace std;

int main(void)
{
	int n, score[110], num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> score[i];
	}
	for (int i = 0; i < n; i++)
	{
		num = 0;
		for (int j = 0; j < i; j++)
		{
			if (score[j] < score[i])
			{
				num++;
			}
		}
		cout << num << ' ';
	}
	return 0;
}