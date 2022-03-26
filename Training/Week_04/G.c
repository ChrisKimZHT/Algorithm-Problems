#include <stdio.h>
#include <stdlib.h>

int main()
{
	int count, a, b, c;
	char temp;
	scanf("%d", &count);
	getchar();
	while (count--)
	{
		a = b = c = 0;
		while ((temp = getchar()) != '\n')
		{
			if (temp == 'A')
				a++;
			else if (temp == 'B')
				b++;
			else if (temp == 'C')
				c++;
		}
		if (b == a + c)
			printf("YES\n");
		else
			printf("NO\n");
	}
	system("pause");
	return 0;
}