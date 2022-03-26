#include <bits/stdc++.h>
using namespace std;

struct awa
{
	int start;
	int end;
};

bool cmp(struct awa a, struct awa b);

int main()
{
	int count, ans, selected;
	while (scanf("%d", &count) != EOF)
	{
		if (count == 0)
			break;
		struct awa time[100];
		ans = 1;
		selected = 0;
		for (int i = 0; i < count; i++)
			scanf("%d%d", &time[i].start, &time[i].end);
		sort(time, time + count, cmp);
		for (int i = 1; i < count; i++)
		{
			if (time[selected].end > time[i].start)
				continue;
			else
			{
				selected = i;
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	system("pause");
	return 0;
}

bool cmp(struct awa a, struct awa b)
{
	return a.end < b.end;
}