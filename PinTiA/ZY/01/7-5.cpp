#include <iostream>

using namespace std;

int main(void)
{
	int choice, count = 5;
	cout << "[1] apple\n[2] pear\n[3] orange\n[4] grape\n[0] exit\n";
	while (count--)
	{
		cin >> choice;
		if (!choice)
		{
			break;
		}
		switch (choice)
		{
		case 1:
			cout << "price = 3.00\n";
			break;

		case 2:
			cout << "price = 2.50\n";
			break;

		case 3:
			cout << "price = 4.10\n";
			break;

		case 4:
			cout << "price = 10.20\n";
			break;

		default:
			cout << "price = 0.00\n";
			break;
		}
	}
	return 0;
}