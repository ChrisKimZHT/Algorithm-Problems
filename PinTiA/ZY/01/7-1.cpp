#include <iostream>

using namespace std;

int main(void)
{
	int N, A = 0, B = 0, C = 0;
	cin >> N;
	while (N--)
	{
		int score;
		cin >> score;
		if (score >= 85)
		{
			A++;
		}
		else if (score >= 60)
		{
			B++;
		}
		else
		{
			C++;
		}
	}
	cout << A << ' ' << B << ' ' << C;
	return 0;
}