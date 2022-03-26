#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	string S;
	cin >> S;
	int l = 0, r = S.length() - 1;
	bool flag = true;
	while (S[l] == 'a')
	{
		l++;
	}
	while (S[r] == 'a')
	{
		r--;
	}
	if (l > S.length() - 1 - r)
	{
		flag = false;
	}
	while (l < r)
	{
		if (!flag)
			break;
		if (S[l] == S[r])
		{
			l++;
			r--;
		}
		else
		{
			flag = false;
		}
	}
	if (flag)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}