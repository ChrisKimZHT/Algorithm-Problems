#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int x;
	cin >> x;
	int fen5, fen2, fen1;
	int count = 0;
	fen5 = x / 5;
	do
	{
		fen2 = (x - fen5 * 5) / 2;
		do
		{
			fen1 = x - fen5 * 5 - fen2 * 2;
			if (fen1 == 0)
			{
				fen2--;
				continue;
			}
			printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", fen5, fen2, fen1, fen5 + fen2 + fen1);
			count++;
			fen2--;
		} while (fen2 >= 1);
		fen5--;
	} while (fen5 >= 1);
	cout << "count = " << count << endl;
	return 0;
}