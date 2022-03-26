#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	char a;
	map<char, int> charcnt;
	while (cin >> a)
	{
		charcnt[a]++;
	}
	int maxi = 0, mini = 101;
	for (map<char, int>::iterator iter = charcnt.begin(); iter != charcnt.end(); iter++)
	{
		maxi = max(maxi, iter->second);
		mini = min(mini, iter->second);
	}
	bool prime = true;
	for (int i = 2; i < maxi - mini; i++)
	{
		if ((maxi - mini) % i == 0)
		{
			prime = false;
		}
	}
	if (prime && (maxi - mini) > 1)
	{
		cout << "Lucky Word" << endl;
		cout << maxi - mini << endl;
	}
	else
	{
		cout << "No Answer" << endl;
		cout << '0' << endl;
	}
	return 0;
}