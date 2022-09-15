#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int N, a[MAXN];

void quick_sort(int arr[], int l, int r)
{
	if (l >= r)
		return;
	int mid = arr[l + r >> 1];
	int x = l - 1, y = r + 1;
	while (x < y)
	{
		do
		{
			x++;
		} while (arr[x] < mid);
		do
		{
			y--;
		} while (arr[y] > mid);
		if (x < y)
			swap(arr[x], arr[y]);
	}
	quick_sort(arr, l, y);
	quick_sort(arr, y + 1, r);
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	quick_sort(a, 0, N - 1);
	for (int i = 0; i < N; i++)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}