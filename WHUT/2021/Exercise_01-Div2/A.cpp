#include <bits/stdc++.h>

using namespace std;

struct version
{
	int ver[100];
	int length = 0;
};

bool cmp(version, version);

int main(void)
{
	version arr[100];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num, j = 0;
		char sep = '.';
		while (sep == '.')
		{
			scanf("%d%c", &num, &sep);
			arr[i].ver[j] = num;
			arr[i].length++;
			j++;
		}
	}
	sort(arr, arr + N, cmp);
	// cout << "-----" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < arr[i].length; j++)
		{
			if (j)
				cout << '.';
			cout << arr[i].ver[j];
		}
		cout << '\n';
	}
	return 0;
}

bool cmp(version a, version b)
{
	for (int i = 0; i <= min(a.length, b.length); i++)
	{
		if (a.ver[i] > b.ver[i])
			return 0;
		else if (a.ver[i] < b.ver[i])
			return 1;
	}
	if (a.length > b.length)
		return 0;
	else
		return 1;
}