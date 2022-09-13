#include <bits/stdc++.h>

using namespace std;

struct STU
{
	int id;
	string name;
	int score;
};

bool cmp(STU, STU);

int main(void)
{
	int N;
	while (cin >> N)
	{
		STU student[300], srtstu[300];
		for (int i = 0; i < N; i++)
		{
			student[i].id = i;
			cin >> student[i].name >> student[i].score;
		}
		for (int i = 0; i < N; i++)
		{
			srtstu[i].id = i;
			cin >> srtstu[i].name >> srtstu[i].score;
		}
		bool is_right = true;
		for (int i = 0; i < N - 1; i++)
		{
			if (srtstu[i].score < srtstu[i + 1].score)
			{
				is_right = false;
				break;
			}
		}
		sort(student, student + N, cmp);
		if (is_right)
		{
			bool is_stable = true;
			for (int i = 0; i < N; i++)
			{
				if (srtstu[i].name != student[i].name)
				{
					is_stable = false;
					break;
				}
			}
			if (is_stable)
			{
				cout << "Right" << endl;
			}
			else
			{
				cout << "Not Stable" << endl;
				for (int j = 0; j < N; j++)
				{
					cout << student[j].name << ' ' << student[j].score << endl;
				}
			}
		}
		else
		{
			cout << "Error" << endl;
			for (int i = 0; i < N; i++)
			{
				cout << student[i].name << ' ' << student[i].score << endl;
			}
		}
	}
	return 0;
}

bool cmp(STU a, STU b)
{
	if (a.score > b.score)
		return 1;
	else if (a.score < b.score)
		return 0;
	else
	{
		if (a.id < b.id)
			return 1;
		else
			return 0;
	}
}