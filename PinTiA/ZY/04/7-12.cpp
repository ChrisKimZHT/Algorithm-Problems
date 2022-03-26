#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int Y, M, D;
	int day[2][12]{
		{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	scanf("%d/%d/%d", &Y, &M, &D);
	if (Y % 4 == 0 && Y % 100 != 0 || Y % 400 == 0)
	{
		int ans = 0;
		for (int i = 0; i < M - 1; i++)
			ans += day[1][i];
		ans += D;
		cout << ans << endl;
	}
	else
	{
		int ans = 0;
		for (int i = 0; i < M - 1; i++)
			ans += day[0][i];
		ans += D;
		cout << ans << endl;
	}
	return 0;
}