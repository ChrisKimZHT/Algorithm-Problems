#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int length = 0;
	char in[100];
	while ((in[length] = getchar()) != '\n')
		length++;
	int offset;
	cin >> offset;
	for (int i = 0; i < length; i++)
	{
		if (in[i] >= 'A' && in[i] <= 'Z')
		{
			cout << char(((in[i] - 'A' + offset > 0) ? in[i] - 'A' + offset : in[i] - 'A' + offset + 26) % 26 + 'A');
		}
		else if (in[i] >= 'a' && in[i] <= 'z')
		{
			cout << char(((in[i] - 'a' + offset > 0) ? in[i] - 'a' + offset : in[i] - 'a' + offset + 26) % 26 + 'a');
		}
		else
		{
			cout << in[i];
		}
	}
	return 0;
}