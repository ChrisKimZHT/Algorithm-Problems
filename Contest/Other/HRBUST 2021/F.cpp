#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	char S[2021];
	for (int i = 0; i < N; i++)
	{
		cin >> S[i];
	}
	int l = 0, r = N - 1;
	for (int i = 0; i < N; i++)
	{
		char temp;
		if (l == r)
		{
			cout << S[l];
		}
		else
		{
			if (S[l] < S[r])
			{
				temp = S[l++];
			}
			else if (S[l] > S[r])
			{
				temp = S[r--];
			}
			else
			{
				int n = 1;
				bool a = false;
				while ((l + n) < (r - n))
				{
					if (S[l + n] < S[r - n])
					{
						temp = S[l++];
						a = true;
						break;
					}
					else if (S[l + n] > S[r - n])
					{
						temp = S[r--];
						a = true;
						break;
					}
					else
					{
						n++;
					}
				}
				if (!a)
				{
					temp = S[l++];
				}
			}
			cout << temp;
		}
	}
	return 0;
}