#include<bits/stdc++.h>
using namespace std;

int main()
{
	int icount, ocount = 1, temp;
	scanf("%d", &icount);
	int num[icount];
	scanf("%d", &num[0]);
	for (int i = 1; i < icount; i++)
	{
		scanf("%d", &temp);
		for (int j = 0; j < ocount; j++)
		{
			if (temp != num[j] && j == ocount - 1)
			{
				num[j + 1] = temp;
				ocount++;
			}
			else if (temp == num[j])
			{
				break;
			}
		}
	}
	sort(num, num + ocount);
	printf("%d\n", ocount);
	for (int k = 0; k < ocount; k++)
	{
		printf("%d", num[k]);
		if (k != ocount - 1)
		{
			printf(" ");
		}
	}
	system("pause");
	return 0;
}