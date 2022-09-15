#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	double distance, per = 2, swim = 0;
	int count;
	cin >> distance;
	for (count = 0; swim < distance; count++)
	{
		swim += per;
		per *= 0.98;
	}
	cout << count;
	return 0;
}