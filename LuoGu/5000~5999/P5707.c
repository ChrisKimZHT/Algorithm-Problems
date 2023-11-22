#include <stdio.h>

int main(void)
{
	int s, v, a, b;
	scanf("%d%d", &s, &v);
	int walk, time, temp;
	walk = s / v;
	if (s % v != 0)
		walk++;
	time = walk + 10;
	temp = 480 - time;
	if (temp >= 0)
	{
		a = temp / 60;
		b = temp % 60;
	}
	else
	{
		temp += 1440;
		a = temp / 60;
		b = temp % 60;
	}
	printf("%02d:%02d", a, b);
}