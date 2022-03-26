#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

double f(double x, int N, double *X, double *W);

int main(void)
{
	int T;
	double X[50000], W[50000];
	double eps = 1e-6;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int N;
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
		{
			scanf("%lf%lf", &X[j], &W[j]);
		}
		double l = X[0], r = X[N - 1];
		while (r - l > eps)
		{
			double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
			if (f(m1, N, X, W) > f(m2, N, X, W))
				l = m1;
			else
				r = m2;
		}
		double ans = f(l, N, X, W);
		int _ans = (int)(ans + 0.5) > (int)ans ? (int)ans + 1 : (int)ans;
		printf("Case #%d: %d\n", i + 1, _ans);
	}
	system("pause");
	return 0;
}

double f(double x, int N, double *X, double *W)
{
	double ans[50000];
	double ret = 0;
	for (int i = 0; i < N; i++)
	{
		ans[i] = pow(abs(x - X[i]), 3) * W[i];
	}
	for (int i = 0; i < N; i++)
	{
		ret += ans[i];
	}
	return ret;
}