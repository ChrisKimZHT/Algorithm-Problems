#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int k;
	cin >> k;
	string s;
	cin >> s;
	int cnt = 1;
	bool flag = false;
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] == s[i - 1])
		{
			cnt++;
		}
		else
		{
			if (cnt >= k)
			{
				flag = true;
				cout << s[i - 1];
				break;
			}
			cnt = 1;
		}
	}
	if (!flag)
		cout << "No" << endl;
	return 0;
}