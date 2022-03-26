#include <stdio.h>
#include <stdlib.h>

int main()
{
	int y, m, d, month[12], i;
	month[0] = 31;
	month[2] = 31;
	month[3] = 30;
	month[4] = 31;
	month[5] = 30;
	month[6] = 31;
	month[7] = 31;
	month[8] = 30;
	month[9] = 31;
	month[10] = 30;
	month[11] = 31;
	while (scanf("%d%*c%d%*c%d", &y, &m, &d) != EOF)
	{
		int result = 0;
		if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		{
			month[1] = 29;
			for (i = 0; i < m - 1; i++)
			{
				result += month[i];
			}
			result += d;
			printf("%d\n", result);
		}
		else
		{
			month[1] = 28;
			for (i = 0; i < m - 1; i++)
			{
				result += month[i];
			}
			result += d;
			printf("%d\n", result);
		}
	}
	//system("pause");
	return 0;
}
	