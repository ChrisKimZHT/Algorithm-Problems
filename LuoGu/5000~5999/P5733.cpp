#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	string in;
	cin >> in;
	for (int i = 0; i < in.length(); i++)
	{
		if (islower(in[i]))
		{
			printf("%c", in[i] + 'A' - 'a');
		}
		else
		{
			cout << in[i];
		}
	}
	cout << endl;
	return 0;
}