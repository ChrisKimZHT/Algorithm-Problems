#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N1, arr1[20], cnt1 = 0;
	cin >> N1;
	for (int i = 0; i < N1; i++)
	{
		int tmp;
		cin >> tmp;
		bool exist = false;
		for (int j = 0; j < cnt1; j++)
		{
			if (arr1[j] == tmp)
				exist = true;
		}
		if (!exist)
			arr1[cnt1++] = tmp;
	}
	int N2, arr2[20], cnt2 = 0;
	cin >> N2;
	for (int i = 0; i < N2; i++)
	{
		int tmp;
		cin >> tmp;
		bool exist = false;
		for (int j = 0; j < cnt2; j++)
		{
			if (arr2[j] == tmp)
				exist = true;
		}
		if (!exist)
			arr2[cnt2++] = tmp;
	}
	int ans[40], anscnt = 0;
	for (int i = 0; i < cnt1; i++)
	{
		bool same = false;
		for (int j = 0; j < cnt2; j++)
		{
			if (arr1[i] == arr2[j])
				same = true;
		}
		if (!same)
		{
			bool exist = false;
			for (int k = 0; k < anscnt; k++)
			{
				if (ans[k] == arr1[i])
				{
					exist = true;
				}
			}
			if (!exist)
			{
				ans[anscnt++] = arr1[i];
			}
		}
	}
	for (int i = 0; i < cnt2; i++)
	{
		bool same = false;
		for (int j = 0; j < cnt1; j++)
		{
			if (arr2[i] == arr1[j])
				same = true;
		}
		if (!same)
		{
			bool exist = false;
			for (int k = 0; k < anscnt; k++)
			{
				if (ans[k] == arr2[i])
				{
					exist = true;
				}
			}
			if (!exist)
			{
				ans[anscnt++] = arr2[i];
			}
		}
	}
	for (int i = 0; i < anscnt; i++)
	{
		if (i)
			cout << ' ';
		cout << ans[i];
	}
	return 0;
}