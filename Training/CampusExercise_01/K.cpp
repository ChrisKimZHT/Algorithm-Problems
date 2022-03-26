#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	map<char, char> DNA;
	DNA['A'] = 'T';
	DNA['T'] = 'A';
	DNA['C'] = 'G';
	DNA['G'] = 'C';
	char c;
	while (cin >> c)
	{
		cout << DNA[c];
	}
	return 0;
}