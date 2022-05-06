// STL版本
#include <bits/stdc++.h>

using namespace std;

void ins(int, int, int);
void del(int);
void print(void);

list<int> a;
list<int>::iterator pos[100100];
bool erased[100100]{};

int main(void)
{
	a.push_front(1);
	pos[1] = a.begin();
	int N;
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		int k, p;
		cin >> k >> p;
		ins(i, k, p);
	}
	int M;
	cin >> M;
	while (M--)
	{
		int x;
		cin >> x;
		del(x);
	}
	print();
	return 0;
}

void ins(int n, int k, int p)
{
	if (p == 0)
	{
		pos[n] = a.insert(pos[k], n);
	}
	else if (p == 1)
	{
		pos[n] = a.insert(next(pos[k]), n);
	}
}

void del(int x)
{
	if (!erased[x])
		a.erase(pos[x]);
	erased[x] = true;
}

void print(void)
{
	for (list<int>::iterator iter = a.begin(); iter != a.end(); ++iter)
	{
		cout << *iter << ' ';
	}
}
// 非STL版本
/*#include <bits/stdc++.h>

using namespace std;

void init(void);
void ins(int, int, int);
void del(int);
void print(void);

struct node
{
	int L, R;
} a[100100];

int main(void)
{
	init();
	int N;
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		int k, p;
		cin >> k >> p;
		ins(i, k, p);
	}
	int M;
	cin >> M;
	while (M--)
	{
		int x;
		cin >> x;
		del(x);
	}
	print();
	return 0;
}

void init(void)
{
	a[0].L = -1;
	a[0].R = 1;
	a[1].L = 0;
	a[1].R = -1;
}

void ins(int n, int k, int p)
{
	if (p == 0)
	{
		if (a[k].L != -1)
		{
			a[a[k].L].R = n;
			a[n].L = a[k].L;
			a[k].L = n;
			a[n].R = k;
		}
		else if (a[k].L == -1)
		{
			a[k].L = n;
			a[n].R = k;
			a[n].L = -1;
		}
	}
	else if (p == 1)
	{
		if (a[k].R != -1)
		{
			a[a[k].R].L = n;
			a[n].R = a[k].R;
			a[k].R = n;
			a[n].L = k;
		}
		else if (a[k].R == -1)
		{
			a[k].R = n;
			a[n].L = k;
			a[n].R = -1;
		}
	}
	return;
}

void del(int x)
{
	if (!(a[x].R == -1 && a[x].L == -1))
	{
		if (a[x].L != -1 && a[x].R != -1)
		{
			a[a[x].L].R = a[x].R;
			a[a[x].R].L = a[x].L;
		}
		else if (a[x].L != -1 && a[x].R == -1)
		{
			a[a[x].L].R = -1;
		}
		else if (a[x].L == -1 && a[x].R != -1)
		{
			a[a[x].R].L = -1;
		}
		a[x].R = a[x].L = -1;
	}
	return;
}

void print(void)
{
	int next = a[0].R;
	while (next != -1)
	{
		cout << next << ' ';
		next = a[next].R;
	}
	return;
}
*/