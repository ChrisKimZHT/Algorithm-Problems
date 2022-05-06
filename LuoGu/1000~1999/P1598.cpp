#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	char tmp;
	char chart[26][401];
	map<char, int> cnt;
	while (cin >> tmp)
	{
		if (isalpha(tmp))
			cnt[tmp]++;
	}
	int maxcnt = 0;
	for (int i = 0; i < 26; i++)
	{
		chart[i][0] = i + 'A';
		maxcnt = max(maxcnt, cnt[char(i + 'A')]);
		for (int j = 1; j <= 400; j++)
		{
			if (j <= cnt[char(i + 'A')])
				chart[i][j] = '*';
			else
				chart[i][j] = ' ';
		}
	}
	for (int i = maxcnt; i >= 0; i--)
	{
		for (int j = 0; j < 26; j++)
		{
			if (j)
				cout << ' ';
			cout << chart[j][i];
		}
		cout << endl;
	}
	return 0;
}