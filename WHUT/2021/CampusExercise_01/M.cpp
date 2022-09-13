#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); i++)
	{
		s1[i] = tolower(s1[i]);
	}
	for (int i = 0; i < s2.length(); i++)
	{
		s2[i] = tolower(s2[i]);
	}
	if (s1 < s2)
	{
		cout << "<" << endl;
	}
	else if (s1 > s2)
	{
		cout << ">" << endl;
	}
	else
	{
		cout << "=" << endl;
	}
	return 0;
}