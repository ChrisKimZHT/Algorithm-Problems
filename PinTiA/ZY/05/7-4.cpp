#include <bits/stdc++.h>

using namespace std;

struct BOOK
{
	string name;
	double price;
};

bool cmp(BOOK, BOOK);

int main(void)
{
	int n;
	BOOK book[10];
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++)
	{
		getline(cin, book[i].name);
		cin >> book[i].price;
		getchar();
	}
	sort(book, book + n, cmp);
	printf("%.2lf, %s\n", book[n - 1].price, book[n - 1].name.c_str());
	printf("%.2lf, %s", book[0].price, book[0].name.c_str());
	return 0;
}

bool cmp(BOOK a, BOOK b)
{
	if (a.price > b.price)
		return 0;
	else
		return 1;
}