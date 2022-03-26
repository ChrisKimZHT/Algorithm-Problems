#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int id, a, b;
		cin >> id >> a >> b;
		if ((a + b) > 140 && (0.7 * a + 0.3 * b) >= 80)
		{
			cout << "Excellent" << endl;
		}
		else
		{
			cout << "Not excellent" << endl;
		}
	}
	return 0;
}