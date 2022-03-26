#include <bits/stdc++.h>

using namespace std;

int improve(int grade)
{
	int tmp = grade * 1.2;
	if (tmp >= 600)
	{
		return 600;
	}
	else
	{
		return tmp;
	}
}

int main(void)
{
	int n;
	cin >> n;
	string name;
	int age, grade;
	while (n--)
	{
		cin >> name >> age >> grade;
		cout << name << ' ' << age + 1 << ' ' << improve(grade) << endl;
	}
	return 0;
}