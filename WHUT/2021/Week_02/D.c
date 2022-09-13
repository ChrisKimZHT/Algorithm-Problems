#include <stdio.h>
float f(float x);

int main()
{
	float i, o;
	scanf("%f", &i);
	o = f(i);
	printf("%.3f", o);
	return 0;
}

float f(float x)
{
	if(x >= 0 && x < 5 )
	{
		return 2.5 - x;
	}
	else if(x >= 5 && x < 10)
	{
		return 2 - 1.5 * (x - 3) * (x - 3);
	}
	else if(x >= 10 && x<20)
	{
		return 0.5 * x - 1.5;
	}
}