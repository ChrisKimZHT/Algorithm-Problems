#include <stdio.h>

int MonthDays(int year, int month);

int main()
{
	int ndays, month, year;

	scanf("%d", &year);
	for (month = 1; month <= 12; month++)
	{
		ndays = MonthDays(year, month);
		printf("%d ", ndays);
	}

	return 0;
}

/* 你的代码将被嵌在这里 */
int MonthDays(int year, int month)
{
	int day[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
					  {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return day[1][month - 1];
	else
		return day[0][month - 1];
}