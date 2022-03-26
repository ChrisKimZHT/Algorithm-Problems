#include<bits/stdc++.h>
using namespace std;

struct info
{
	int hp;
	int dps;
	double hp_dps;
} a[20];

bool cmp(struct info a, struct info b);

int main()
{
	int enemy, loss, dps;

	while (scanf("%d", &enemy) != EOF)
	{
		loss = 0;
		dps = 0;
		for (int i = 0; i < enemy; i++)
		{
			scanf("%d%d", &a[i].dps, &a[i].hp);
			a[i].hp_dps = 1.0 * a[i].hp / a[i].dps;
			dps += a[i].dps;
		}
		sort(a, a + enemy, cmp);
		for (int i = 0; i < enemy; i++)
		{
			loss += dps * a[i].hp;
			dps -= a[i].dps;
		}
		printf("%d\n", loss);
	}
	system("pause");
	return 0;
}

bool cmp(struct info a, struct info b)
{
	return a.hp_dps < b.hp_dps;
}