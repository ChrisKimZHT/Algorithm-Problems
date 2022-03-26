#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	while (1)
	{
		int N;
		cin >> N;
		if (!N)
			break;
		map<string, int> balloon;
		for (int i = 0; i < N; i++)
		{
			string color;
			cin >> color;
			balloon[color]++;
		}
		int max = 0;
		string maxcolor;
		for (map<string, int>::iterator iter = balloon.begin(); iter != balloon.end(); iter++)
		{
			if (iter->second > max)
			{
				max = iter->second;
				maxcolor = iter->first;
			}
		}
		cout << maxcolor << endl;
	}
	return 0;
}