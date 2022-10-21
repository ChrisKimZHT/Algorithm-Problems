#include <bits/stdc++.h>
#define SIZE 100010

using namespace std;

vector<int> max_20_value[SIZE];
vector<int> link[SIZE];
int father[SIZE] = {0, 1};
vector<int> son[SIZE];

void creat_tree(int x)
{
	for (auto i : link[x])
	{
		if (father[i])
			continue;
		father[i] = x;
		son[x].push_back(i);
		creat_tree(i);
	}
}

void calc_max_20_value(int x)
{
	for (auto i : son[x])
	{
		calc_max_20_value(i);
		for (auto j : max_20_value[i])
		{
			max_20_value[x].push_back(j);
		}
	}
	sort(max_20_value[x].begin(), max_20_value[x].end());
	while (max_20_value[x].size() > 20)
	{
		max_20_value[x].erase(max_20_value[x].begin());
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, Q;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++)
	{
		int X;
		cin >> X;
		max_20_value[i].push_back(X);
	}
	for (int i = 1; i < N; i++)
	{
		int A, B;
		cin >> A >> B;
		link[A].push_back(B);
		link[B].push_back(A);
	}
	creat_tree(1);
	calc_max_20_value(1);
	for (int i = 1; i <= Q; i++)
	{
		int N, Q;
		cin >> N >> Q;
		cout << max_20_value[N][max_20_value[N].size() - Q] << endl;
	}
	return 0;
}