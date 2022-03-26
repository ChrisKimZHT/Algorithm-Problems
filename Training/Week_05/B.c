#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	long long a[50001];
	a[0] = 0;
	int count, ans = 0;
	scanf("%d", &count);
	for (int i = 0; i < count; i++)
	{
		int temp = 0;
		scanf("%d", &temp);
		a[i + 1] = (a[i] + temp) % 7;
	}

	for (int i = 1; i <= 7; i++)
	{
		int left, right;
		for (left = 0; left < count; left++)
		{
			if (a[left] == i)
				break;
		}
		for (right = count; right > 0; right--)
		{
			if (a[right] == i)
				break;
		}
		if (ans > right - left)
			continue;
		else
			ans = right - left;
	}
	
	// for (int i = 0; i < count + 1; i++)
	// {
	// 	for (int j = 0; j < i; j++)
	// 	{
	// 		if (ans > i - j)
	// 			continue;
	// 		if (a[i] - a[j] == 0)
	// 			ans = i - j;
	// 	}
	// }

	printf("%d", ans);
	system("pause");
	return 0;
}