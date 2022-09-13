#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.length(); i++)
	{
		if (isupper(s[i]))
		{
			s[i] += 3;
			if (s[i] > 'Z')
				s[i] -= 26;
			s[i] = tolower(s[i]);
		}
		else
		{
			s[i] += 3;
			if (s[i] > 'z')
				s[i] -= 26;
			s[i] = toupper(s[i]);
		}
	}
	cout << s << endl;
	return 0;
}