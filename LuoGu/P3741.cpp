#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	char s[200]{};
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	bool change = true;
	for (int i = 0; i < n; i++)
	{
		if (i + 1 < n && s[i] == 'V' && s[i + 1] == 'K')
		{
			cnt++;
			i++;
		}
		else if (change && s[i] == 'K' && s[i + 1] == 'K')
		{
			change = false;
			cnt++;
			i++;
		}
		else if (change && s[i] == 'V' && s[i + 1] == 'V' && s[i + 2] != 'K')
		{
			change = false;
			cnt++;
			i++;
		}
	}
	cout << cnt << endl;
	return 0;
}