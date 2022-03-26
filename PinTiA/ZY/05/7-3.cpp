#include <bits/stdc++.h>

using namespace std;

struct STU
{
	string id;
	string name;
	int score;
};

int main(void)
{
	int N;
	cin >> N;
	STU student[10];
	double average = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> student[i].id >> student[i].name >> student[i].score;
		average += student[i].score;
	}
	average /= N;
	printf("%.2lf\n", average);
	for (int i = 0; i < N; i++)
	{
		if (student[i].score < average)
		{
			cout << student[i].name << ' ' << student[i].id << endl;
		}
	}
	return 0;
}