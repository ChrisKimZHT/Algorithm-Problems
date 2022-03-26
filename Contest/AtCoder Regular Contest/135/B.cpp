#include <bits/stdc++.h>
#define MAXN 300010

using namespace std;

long long S[MAXN];
long long L[MAXN];
long long A[MAXN];

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> S[i];
	}
	L[0] = L[1] = 0;
	for (int i = 0; i < N; i++)
	{
		L[i + 2] = S[i] - L[i + 1] - L[i];
	}
	long long lim_a = 0, lim_b = 0, lim_ab = INT64_MAX;
	bool flag = true;
	for (int i = 2; i < N + 2; i++)
	{
		if (i % 3 == 0)
		{
			lim_a = max(lim_a, L[i] < 0 ? -L[i] : 0);
		}
		else if (i % 3 == 1)
		{
			lim_b = max(lim_b, L[i] < 0 ? -L[i] : 0);
		}
		else
		{
			lim_ab = min(lim_ab, L[i]);
		}
	}
	// cout << lim_a << ' ' << lim_b << ' ' << lim_ab << endl;
	if (lim_a + lim_b > lim_ab)
	{
		flag = false;
	}
	if (flag)
	{
		cout << "Yes" << endl;
		A[0] = lim_a, A[1] = lim_b;
		cout << A[0] << ' ' << A[1] << ' ';
		for (int i = 0; i < N; i++)
		{
			A[i + 2] = S[i] - A[i] - A[i + 1];
			cout << A[i + 2] << ' ';
		}
		cout << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}