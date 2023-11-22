#include <stdio.h>

int main(void)
{
	char a, b, c, d;
	scanf("%c%c%c%*c%c", &a, &b, &c, &d);
	printf("%c.%c%c%c", d, c, b, a);
	return 0;
}