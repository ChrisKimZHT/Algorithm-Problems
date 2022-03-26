#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	string word;
	string find;
	int pos = 0, cnt = 0;
	int anspos = -1;
	cin >> find;
	getchar();
	while (1)
	{
		char c;
		while ((c = getchar()) == ' ')
		{
			pos++;
		}
		ungetc(c, stdin);
		if (!(cin >> word))
		{
			break;
		}
		if (word.length() != find.length())
		{
			pos += word.length();
			continue;
		}
		else
		{
			bool same = true;
			for (int i = 0; i < find.length(); i++)
			{
				if (isupper(word[i]))
				{
					if (word[i] != find[i] && word[i] != find[i] - 32)
						same = false;
				}
				else if (islower(word[i]))
				{
					if (word[i] != find[i] && word[i] != find[i] + 32)
						same = false;
				}
			}
			if (same)
			{
				cnt++;
				if (anspos == -1)
				{
					anspos = pos;
				}
			}
		}
		pos += word.length();
	}
	if (anspos == -1)
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << cnt << ' ' << anspos << endl;
	}
	return 0;
}