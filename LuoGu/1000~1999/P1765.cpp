#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	map<char, int> key;
	key['a'] = key['d'] = key['g'] = key['j'] = key['m'] = key['p'] = key['t'] = key['w'] = key[' '] = 1;
	key['b'] = key['e'] = key['h'] = key['k'] = key['n'] = key['q'] = key['u'] = key['x'] = 2;
	key['c'] = key['f'] = key['i'] = key['l'] = key['o'] = key['r'] = key['v'] = key['y'] = 3;
	key['s'] = key['z'] = 4;
	string str;
	getline(cin, str);
	int cnt = 0;
	for (int i = 0; i < str.length(); i++)
	{
		cnt += key[str[i]];
	}
	cout << cnt << endl;
	return 0;
}