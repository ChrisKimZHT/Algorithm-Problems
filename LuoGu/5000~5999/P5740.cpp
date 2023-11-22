#include <bits/stdc++.h>

using namespace std;

struct SCORE
{
	string name;
	int chinese, maths, english, sum;
	int id;
};

bool cmp(SCORE a, SCORE b)
{
	if (a.sum != b.sum)
		return a.sum > b.sum;
	else
		return a.id < b.id;
}

int main(void)
{
	int N;
	cin >> N;
	SCORE student[1000];
	for (int i = 0; i < N; i++)
	{
		student[i].id = i;
		cin >> student[i].name >> student[i].chinese >> student[i].maths >> student[i].english;
		student[i].sum = student[i].chinese + student[i].maths + student[i].english;
	}
	sort(student, student + N, cmp);
	printf("%s %d %d %d", student[0].name.c_str(), student[0].chinese, student[0].maths, student[0].english);
	return 0;
}