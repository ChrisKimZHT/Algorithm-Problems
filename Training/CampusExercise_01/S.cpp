#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);

double V[10000];
double esp = 1e-5;

int cnt(double x, int n)
{
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += floor(V[i] / x);
	}
	return ans;
}

int main(void)
{
	int N, F;
	cin >> N >> F;
	double sum = 0;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		V[i] = PI * t * t;
		sum += V[i];
	}
	double l = 0, r = sum;
	while (r - l >= esp)
	{
		double mid = (l + r) / 2;
		if (cnt(mid, N) >= F + 1)
		{
			l = mid;
		}
		else
		{
			r = mid;
		}
	}
	printf("%.3lf", r);
	return 0;
}