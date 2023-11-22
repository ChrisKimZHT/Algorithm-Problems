#include <bits/stdc++.h>

using namespace std;

struct student
{
	int id, chin, math, engl, sum;
} score[310];

bool cmp(student a, student b)
{
	if (a.sum > b.sum)
	{
		return 1;
	}
	else if (a.sum < b.sum)
	{
		return 0;
	}
	else
	{
		if (a.chin > b.chin)
		{
			return 1;
		}
		else if (a.chin < b.chin)
		{
			return 0;
		}
		else
		{
			if (a.id < b.id)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> score[i].chin >> score[i].math >> score[i].engl;
		score[i].id = i + 1;
		score[i].sum = score[i].chin + score[i].math + score[i].engl;
	}
	sort(score, score + n, cmp);
	for (int i = 0; i < 5; i++)
	{
		cout << score[i].id << ' ' << score[i].sum << endl;
	}
	return 0;
}