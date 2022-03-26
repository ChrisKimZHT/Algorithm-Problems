#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	while (N--)
	{
		string name;
		double basic, addit, spend;
		cin >> name >> basic >> addit >> spend;
		printf("%s %.2lf\n", name.c_str(), basic + addit - spend);
	}
	return 0;
}