#include <iostream>
#define LENGTH 10010

using namespace std;

int main(void)
{
	int l, m, u, v;
	bool tree[LENGTH] = {false};
	cin >> l >> m;
	for (int i = 0; i < l + 1; i++)
	{
		tree[i] = true;
	}
	while (m--)
	{
		cin >> u >> v;
		for (int i = u; i <= v; i++)
		{
			tree[i] = false;
		}
	}
	int count = 0;
	for (int i = 0; i < LENGTH; i++)
	{
		if (tree[i])
		{
			count++;
		}
	}
	cout << count << endl;
	return 0;
}