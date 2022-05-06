#include <bits/stdc++.h>

using namespace std;

struct DATA
{
	string name;
	int chi, mat, eng, sum;
} grade[1000];

bool judge(int a, int b)
{
	if (abs(grade[a].chi - grade[b].chi) <= 5 &&
		abs(grade[a].mat - grade[b].mat) <= 5 &&
		abs(grade[a].eng - grade[b].eng) <= 5 &&
		abs(grade[a].sum - grade[b].sum) <= 10)
		return true;
	else
		return false;
}

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> grade[i].name >> grade[i].chi >> grade[i].mat >> grade[i].eng;
		grade[i].sum = grade[i].chi + grade[i].mat + grade[i].eng;
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (judge(i, j))
			{
				cout << grade[i].name << ' ' << grade[j].name << endl;
			}
		}
	}
	return 0;
}