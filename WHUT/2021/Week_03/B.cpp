#include <bits/stdc++.h>
using namespace std;

int main()
{
	int count;
	scanf("%d", &count);
	struct date
	{
		int y;
		int m;
		int d;
	};
	struct date str[count], temp;
	for (int i = 0; i < count; i++)
	{
		scanf("%d%*c%d%*c%d", &str[i].m, &str[i].d, &str[i].y);
	}

	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - 1 - i; j++)
		{
			if (str[j].y > str[j + 1].y)
			{
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
			else if (str[j].y == str[j + 1].y)
			{
				if (str[j].m > str[j + 1].m)
				{
					temp = str[j];
					str[j] = str[j + 1];
					str[j + 1] = temp;
				}
				else if (str[j].m == str[j + 1].m)
				{
					if (str[j].d > str[j + 1].d)
					{
					temp = str[j];
					str[j] = str[j + 1];
					str[j + 1] = temp;
					}
				}
			}
		}
	}
	for (int i = 0; i < count; i++)
		printf("%02d/%02d/%d\n", str[i].m, str[i].d, str[i].y);
	system("pause");
	return 0;
}