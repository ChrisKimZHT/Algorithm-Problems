#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	map<string, string> dict;
	while (N--)
	{
		string neww, oldw;
		cin >> neww >> oldw;
		dict[oldw] = neww;
	}
	string word;
	stringstream tmp;
	bool flag = true;
	while (cin >> word)
	{
		if (dict.find(word) != dict.end())
		{
			tmp << dict[word] << ' ';
		}
		else
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		cout << tmp.str() << endl;
	}
	else
	{
		cout << "-1" << endl;
	}
	return 0;
}