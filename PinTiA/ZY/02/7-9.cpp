#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N, i;
	cin >> N;
	int last = 1, present = 1;
	for (i = 3; present < N; i++)
	{
		int temp = present;
		present += last;
		last = temp;
	}
	if (N == 1)
		cout << '1' << endl;
	else
		cout << i - 1 << endl;
	return 0;
}