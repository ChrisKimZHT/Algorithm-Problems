#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	string pwd;
	int n;
	cin >> n >> pwd;
	for (int i = 0; i < pwd.length(); i++)
	{
		pwd[i] = (char)((pwd[i] - 97 + n) % 26 + 97);
	}
	cout << pwd;
	return 0;
}