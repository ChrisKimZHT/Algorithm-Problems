#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	bool dot[40010]{};
	int N = 0, i = 0;
	while (1)
	{
		char temp;
		scanf("%c", &temp);
		if (temp != '\n')
		{
			dot[i] = temp - '0';
			i++;
			N++;
		}
		else
		{
			break;
		}
	}
	for (; i < N * N; i++)
	{
		char temp;
		cin >> temp;
		dot[i] = temp - '0';
	}
	cout << N << ' ';
	bool is_one = false;
	int count = 0;
	for (int j = 0; j < N * N; j++)
	{
		if (dot[j] == is_one)
		{
			count++;
		}
		else
		{
			cout << count << ' ';
			count = 1;
			is_one = (is_one) ? false : true;
		}
	}
	cout << count << ' ' << endl;
	return 0;
}