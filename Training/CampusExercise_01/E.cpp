#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	double Xa, Ya, Xb, Yb;
	cin >> Xa >> Ya >> Xb >> Yb;
	printf("%.3lf\n", sqrt(pow(Xa - Xb, 2) + pow(Ya - Yb, 2)));
	return 0;
}