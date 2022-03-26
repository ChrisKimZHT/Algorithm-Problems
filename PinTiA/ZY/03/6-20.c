#include <stdio.h>
#define MAXN 10

void ArrayShift(int a[], int n, int m);

int main()
{
	int a[MAXN], n, m;
	int i;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	ArrayShift(a, n, m);

	for (i = 0; i < n; i++)
	{
		if (i != 0)
			printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");

	return 0;
}

/* 你的代码将被嵌在这里 */
void ArrayShift(int a[], int n, int m)
{
	int temp[MAXN];
	for (int i = 0; i < n; i++)
	{
		temp[(i + m) % n] = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = temp[i];
	}
	return;
}