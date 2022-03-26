#include <bits/stdc++.h>
#define SIZE 1000010

using namespace std;

char s1[SIZE], s2[SIZE];
int nxt[SIZE];

inline void getnext(char *p, int *nxt)
{
	nxt[0] = -1;
	int i = 0, j = -1;
	int lenp = strlen(p);
	while (i < lenp)
	{
		if (j == -1 || p[i] == p[j])
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

inline void kmp(char *t, char *p)
{
	int i = 0;
	int j = 0;
	int lent = strlen(t), lenp = strlen(p);
	while (i < lent)
	{
		if (j == -1 || t[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j = nxt[j];
		}
		if (j == lenp)
		{
			printf("%d\n", i - j + 1);
		}
	}
}

int main(void)
{
	// freopen("C:\\Users\\ChrisKim\\Desktop\\P3375_8.in", "r", stdin);
	// freopen("C:\\Users\\ChrisKim\\Desktop\\P3375_8.out", "w", stdout);
	scanf("%s%s", s1, s2);
	getnext(s2, nxt);
	kmp(s1, s2);
	for (int i = 1; i <= strlen(s2); i++)
	{
		printf("%d ", nxt[i]);
	}
	return 0;
}