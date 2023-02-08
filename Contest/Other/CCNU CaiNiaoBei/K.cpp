#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	int scorea = 0, scoreb = 0, ans = 0;
	bool ten = false;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'W')
			scorea++;
		else
			scoreb++;
		if (scorea == 10 && scoreb == 10)
			ten = true;
		if (ten == false && scorea == 11)
		{
			ans++;
			scorea = scoreb = 0;
			ten = false;
		}
		else if (ten == false && scoreb == 11)
		{
			scorea = scoreb = 0;
			ten = false;
		}
		else if (ten == true && scorea - scoreb >= 2)
		{
			ans++;
			scorea = scoreb = 0;
			ten = false;
		}
		else if (ten == true && scoreb - scorea >= 2)
		{
			scorea = scoreb = 0;
			ten = false;
		}
	}
	cout << ans;
	return 0;
}