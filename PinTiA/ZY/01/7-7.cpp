#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
	int amount, category;
	double price, discount;
	char service;
	cin >> amount >> category >> service;
	if (service == 'm')
	{
		discount = 0.95;
	}
	else if (service == 'e')
	{
		discount = 0.97;
	}
	if (category == 90)
	{
		price = amount * 6.95 * discount;
	}
	else if (category == 93)
	{
		price = amount * 7.44 * discount;
	}
	else if (category == 97)
	{
		price = amount * 7.93 * discount;
	}
	printf("%.2lf", price);
	return 0;
}