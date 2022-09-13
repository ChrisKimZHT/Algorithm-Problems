#include <stdio.h>
#include <stdlib.h>

int main()
{
	int room;
	double ans, catfood;
	struct awa
	{
		int mouse;
		int cat;
		double cperm;
	} food[1000], temp;

	while (scanf("%lf%d", &catfood, &room) != EOF)
	{
		if (catfood == -1 && room == -1)
			break;

		ans = 0;

		// 数据读取
		for (int i = 0; i < room; i++)
		{
			scanf("%d%d", &food[i].mouse, &food[i].cat);
			food[i].cperm = 1.0 * food[i].cat / food[i].mouse;
		}

		// 价格排序
		for (int i = 0; i < room - 1; i++)
		{
			for (int j = 0; j < room - i - 1; j++)
			{
				if (food[j].cperm > food[j + 1].cperm)
				{
					temp = food[j];
					food[j] = food[j + 1];
					food[j + 1] = temp;
				}
			}
		}

		// 购买
		for (int i = 0; i < room; i++)
		{
			double a = 0;
			a = catfood / food[i].cperm;
			if (a >= food[i].mouse)
			{
				ans += food[i].mouse;
				catfood -= food[i].cat;
			}
			else
			{
				ans += catfood / food[i].cperm;
				break;
			}
		}

		// 结果
		printf("%.3f\n", ans);
	}

	system("pause");
	return 0;
}
