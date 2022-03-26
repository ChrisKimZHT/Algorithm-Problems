#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	char ch[81];
	int of;
	gets(ch);
	scanf("%d", &of);
	of %= 26;
	for (int i = 0; i < strlen(ch); i++)
	{
		if (isalpha(ch[i]))
		{
			if (ch[i] >= 65 && ch[i] <= 90)
			{
				if (ch[i] + of >= 65 && ch[i] + of <= 90)
					ch[i] += of;
				else if (ch[i] + of > 90)
					ch[i] = ch[i] + of - 26;
				else if (ch[i] + of < 65)
					ch[i] = ch[i] + of + 26;
			}
			if (ch[i] >= 97 && ch[i] <= 122)
			{
				if (ch[i] + of >= 97 && ch[i] + of <= 122)
					ch[i] += of;
				else if (ch[i] + of > 122)
					ch[i] = ch[i] + of - 26;
				else if (ch[i] + of < 97)
					ch[i] = ch[i] + of + 26;
			}
		}
		printf("%c", ch[i]);
	}
	return 0;
}