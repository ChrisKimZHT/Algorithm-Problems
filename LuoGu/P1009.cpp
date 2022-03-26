#include <iostream>
#include <cstring>
#include <cstdio>
#define LENGTH 100

using namespace std;

void hpadd(int *, int *);
void hpmul(int *, int *);
void hpprint(int *);

// 测试驱动程序
/*
int main(void)
{
	int x[LENGTH] = {0,3}, y[LENGTH] = {9,9};
	// hpadd(x, y);
	hpmul(x, y);
	hpprint(x);
	return 0;
}
*/

// 解题驱动程序
int main(void)
{
	int x[LENGTH] = {1}, fac[LENGTH] = {1}, one[LENGTH] = {1}, S[LENGTH] = {0};
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		hpmul(fac, x);
		hpadd(x, one);
		hpadd(S, fac);
	}
	hpprint(S);
	return 0;
}

void hpadd(int *x, int *y)
{
	int temp = 0;
	for (int i = 0; i < LENGTH; i++)
	{
		x[i] = x[i] + y[i] + temp;
		temp = x[i] / 10;
		x[i] %= 10;
	}
	return;
}

void hpmul(int *x, int *y)
{
	int orgx[LENGTH], temp[LENGTH] = {0};
	for (int i = 0; i < LENGTH; i++)
	{
		orgx[i] = x[i];
		x[i] = 0;
	}
	for (int i = 0; i < LENGTH; i++)
	{
		int tmp = 0;
		for (int j = 0; j < LENGTH; j++)
		{
			temp[j] = orgx[j] * y[i] + tmp;
			tmp = temp[j] / 10;
			temp[j] %= 10;
		}
		for (int j = LENGTH - 1; j >= 0; j--)
		{
			if (j >= i)
			{
				temp[j] = temp[j - i];
			}
			else
			{
				temp[j] = 0;
			}
		}
		hpadd(x, temp);
	}
	return;
}

void hpprint(int *num)
{
	int ishead = false;
	for (int i = LENGTH - 1; i >= 0; i--)
	{
		if (num[i] != 0)
		{
			ishead = true;
		}
		if (ishead)
		{
			printf("%d", num[i]);
		}
	}
	printf("\n");
	return;
}