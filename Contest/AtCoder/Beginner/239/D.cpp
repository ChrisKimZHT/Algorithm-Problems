#include <bits/stdc++.h>
#define SIZE 500

using namespace std;

int main(void)
{
	int prime[SIZE], primesize = 0;
	bool isprime[SIZE];
	memset(isprime, 1, sizeof(isprime));
	isprime[0] = isprime[1] = false;
	for (int i = 2; i < SIZE; i++)
	{
		if (isprime[i])
			prime[primesize++] = i;
		for (int j = 0; j < primesize && i * prime[j] < SIZE; j++)
		{
			isprime[i * prime[j]] = false;
			if (i % prime[j] == 0)
				break;
		}
	}
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	bool flag = false;
	for (int i = A; i <= B; i++)
	{
		for (int j = C; j <= D; j++)
		{
			if (isprime[i + j])
				break;
			if (j == D)
				flag = true;
		}
	}
	if (flag)
		cout << "Takahashi" << endl;
	else
		cout << "Aoki" << endl;
	return 0;
}