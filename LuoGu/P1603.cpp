#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	string word;
	map<string, int> num;
	num["one"] = 1;
	num["two"] = 2;
	num["three"] = 3;
	num["four"] = 4;
	num["five"] = 5;
	num["six"] = 6;
	num["seven"] = 7;
	num["eight"] = 8;
	num["nine"] = 9;
	num["ten"] = 10;
	num["eleven"] = 11;
	num["twelve"] = 12;
	num["thirteen"] = 13;
	num["fourteen"] = 14;
	num["fifteen"] = 15;
	num["sixteen"] = 16;
	num["seventeen"] = 17;
	num["eighteen"] = 18;
	num["nineteen"] = 19;
	num["twenty"] = 20;
	num["a"] = 1;
	num["both"] = 2;
	num["another"] = 1;
	num["first"] = 1;
	num["second"] = 2;
	num["third"] = 3;
	int number[6];
	int i;
	for (i = 0; i < 6; i++)
	{
		cin >> word;
		number[i] = num[word] * num[word] % 100;
	}
	sort(number, number + i);
	bool flag = false, first = true;
	for (int j = 0; j < i; j++)
	{
		if (number[j] != 0)
			flag = true;
		if (flag)
		{
			if (first)
			{
				printf("%d", number[j]);
				first = false;
			}
			else
			{
				printf("%02d", number[j]);
			}
		}
	}
	if (!flag)
		cout << '0';
	return 0;
}