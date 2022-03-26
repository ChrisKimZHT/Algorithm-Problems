#include <iostream>

using namespace std;

int main(void)
{
	double m, n, bmi;
	cin >> m >> n;
	bmi = m / (n * n);
	if (bmi < 18.5)
	{
		printf("Underweight");
	}
	else if (bmi >= 18.5 && bmi < 24)
	{
		printf("Normal");
	}
	else
	{
		cout << bmi << endl;
		printf("Overweight", bmi);
	}
	return 0;
}