#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int N, count = 0;
	cin >> N;
	int score[1000][4];
	for (int i = 0; i < N; i++)
	{
		score[i][3] = 0;
		for (int j = 0; j < 3; j++)
		{
			cin >> score[i][j];
			score[i][3] += score[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (abs(score[i][0] - score[j][0]) <= 5 && abs(score[i][1] - score[j][1]) <= 5 && abs(score[i][2] - score[j][2]) <= 5 && abs(score[i][3] - score[j][3]) <= 10)
			{
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}