#include <bits/stdc++.h>

using namespace std;

char text[10000]{};
int length = 0;

void add(string);
void cut(int, int);
void insert(int, string);
void find(string);

int main(void)
{
	// freopen("D:\\Downloads\\P5734_1.in", "r", stdin);
	// freopen("C:\\Users\\ChrisKim\\Desktop\\a.out", "w", stdout);
	int cntop;
	cin >> cntop;
	getchar();
	// getchar();
	char c;
	while ((c = getchar()) != '\n')
	{
		text[length++] = c;
	}
	while (cntop--)
	{
		int oper;
		cin >> oper;
		if (1 == oper)
		{
			string str;
			cin >> str;
			add(str);
		}
		else if (2 == oper)
		{
			int a, b;
			cin >> a >> b;
			cut(a, b);
		}
		else if (3 == oper)
		{
			int a;
			string str;
			cin >> a >> str;
			insert(a, str);
		}
		else if (4 == oper)
		{
			string str;
			cin >> str;
			find(str);
		}
	}
	return 0;
}

void add(string str)
{
	for (int i = 0; i <= str.length(); i++)
	{
		text[length + i] = str[i];
	}
	length += str.length();
	for (int i = 0; i < length; i++)
	{
		cout << text[i];
	}
	cout << endl;
}

void cut(int a, int b)
{
	stringstream tmp;
	for (int i = a; i < a + b; i++)
	{
		tmp << text[i];
	}
	string _tmp;
	tmp >> _tmp;
	length = _tmp.length();
	for (int i = 0; i < _tmp.length(); i++)
	{
		text[i] = _tmp[i];
	}
	for (int i = 0; i < length; i++)
	{
		cout << text[i];
	}
	cout << endl;
}

void insert(int a, string str)
{
	for (int i = length - 1; i >= a; i--)
	{
		text[i + str.length()] = text[i];
	}
	for (int i = 0; i < str.length(); i++)
	{
		text[a + i] = str[i];
	}
	length += str.length();
	for (int i = 0; i < length; i++)
	{
		cout << text[i];
	}
	cout << endl;
}

void find(string str)
{
	bool exist = false;
	for (int pos = 0; pos <= length - str.length(); pos++)
	{
		bool same = true;
		for (int i = 0; i < str.length(); i++)
		{
			if (text[pos + i] != str[i])
			{
				same = false;
				break;
			}
		}
		if (same)
		{
			cout << pos << endl;
			exist = true;
			break;
		}
	}
	if (!exist)
	{
		cout << "-1" << endl;
	}
}