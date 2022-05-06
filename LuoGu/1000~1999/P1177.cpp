#include <bits/stdc++.h>

using namespace std;

void srt(int *, int *);
int num[100010];
int main(void)
{
	std::ios::sync_with_stdio(false);
	// freopen("D:\\Downloads\\P1177_3.in", "r", stdin);
	// freopen("C:\\Users\\ChrisKim\\Desktop\\a.txt", "w", stdout);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	srt(num, num + N - 1);
	for (int i = 0; i < N; i++)
	{
		cout << num[i] << ' ';
	}
	return 0;
}

void srt(int *start, int *end)
{
	int *l = start, *r = end, *t = l + (r - l) / 2;
	int mid = *t;
	do
	{
		while (*l < mid)
		{
			l++;
		}
		while (*r > mid)
		{
			r--;
		}
		if (l <= r)
		{
			int temp = *r;
			*r = *l;
			*l = temp;
			l++;
			r--;
		}
	} while (l <= r);
	if (start < r)
		srt(start, r);
	if (l < end)
		srt(l, end);
}

/*#include <bits/stdc++.h>

using namespace std;

void qs(int *, int *);
int num[100010];
int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	// random_shuffle(num, num + N);
	qs(num, num + N - 1);
	for (int i = 0; i < N; i++)
	{
		cout << num[i] << ' ';
	}
	return 0;
}

void qs(int *start, int *end)
{
	int *l = start, *r = end;
	int temp = *l;
	while (l < r)
	{
		while (*r >= temp && l < r)
		{
			r--;
		}
		*l = *r;
		while (*l <= temp && l < r)
		{
			l++;
		}
		*r = *l;
	}
	*l = temp;
	if (start < l - 1)
		qs(start, l - 1);
	if (l + 1 < end)
		qs(l + 1, end);
}*/