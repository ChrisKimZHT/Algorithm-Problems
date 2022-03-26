#include <iostream>

using namespace std;

int main(void)
{
	int input;
	bool haveleap = false;
	cin >> input;
	if (input > 2000 && input <= 2100)
	{
		for (int i = 2001; i <= input; i++)
		{
			if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			{
				haveleap = true;
				cout << i << endl;
			}
		}
		if (!haveleap)
		{
			cout << "None" << endl;
		}
	}
	else
	{
		cout << "Invalid year!\n";
	}
	return 0;
}