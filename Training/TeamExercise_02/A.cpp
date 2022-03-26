#include <iostream>
#include <cstring>

using namespace std;

char str[1000010];
int nxt[1000010];

void getnext(void)
{
	nxt[0] = -1;
	int i = 0, j = -1;
	int len = strlen(str);
	while (i < len)
	{
		if (j == -1 || str[i] == str[j])
		{
			++i;
			++j;
			nxt[i] = j;
		}
		else
		{
			j = nxt[j];
		}
	}
}

int main(void)
{
	while (scanf("%s", str) && str[0] != '.')
	{
		getnext();
		int len = strlen(str);
		if (len % (len - nxt[len]))
		{
			printf("1\n");
		}
		else
		{
			printf("%d\n", len / (len - nxt[len]));
		}
	}
	return 0;
}