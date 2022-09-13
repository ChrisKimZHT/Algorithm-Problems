#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int cnt[10];
	int cntodd = 0, odd;
	bool flag = true;
	for (int i = 0; i < 10; i++)
	{
		cin >> cnt[i];
		if (cnt[i] % 2)
		{
			cntodd++;
			odd = i;
		}
		if (i != 0 && cnt[i])
			flag = false;
		cnt[i] /= 2;
	}
	if (odd == 0 && flag)
	{
		cout << "0" << endl;
		return 0;
	}
	if (cntodd > 1)
	{
		cout << "-1" << endl;
	}
	else
	{
		int pos = 0;
		char ans[1000];
		for (int i = 1; i < 10; i++)
		{
			if (cnt[i])
			{
				ans[pos++] = i + '0';
				cnt[i]--;
				break;
			}
			if (i == 9)
			{
				cout << "-1" << endl;
				return 0;
			}
		}
		for (int i = 0; i < 10; i++)
		{
			while (cnt[i])
			{
				ans[pos++] = i + '0';
				cnt[i]--;
			}
		}
		for (int i = 0; i < pos; i++)
		{
			cout << ans[i];
		}
		if (cntodd)
			cout << char(odd + '0');
		for (int i = pos - 1; i >= 0; i--)
		{
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}