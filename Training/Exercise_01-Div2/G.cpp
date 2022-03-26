#include <bits/stdc++.h>

using namespace std;

struct ST
{
	int power, monster;
} cave[100010];

bool cmp(ST a, ST b)
{
	/*if (a.power >= b.power)
		return 0;
	else
		return 1;*/
	return a.power < b.power;
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> cave[i].monster;
			cave[i].power = 0;
			for (int j = 0; j < cave[i].monster; j++)
			{
				int tmp;
				cin >> tmp;
				cave[i].power = max(cave[i].power, tmp - j + 1);
			}
		}
		sort(cave, cave + n, cmp);
		int power = cave[0].power, addi = 0;
		for (int i = 1; i < n; i++)
		{
			power += cave[i - 1].monster;
			if (power >= cave[i].power)
			{
				continue;
			}
			else
			{
				addi += cave[i].power - power;
				power = cave[i].power;
			}
		}
		cout << cave[0].power + addi << endl;
	}
	return 0;
}