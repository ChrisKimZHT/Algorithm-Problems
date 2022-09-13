#include <bits/stdc++.h>

using namespace std;

struct DNA
{
	string seq;
	int cnt;
	int id;
};

bool cmp(DNA, DNA);

int main(void)
{
	DNA dna[100];
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		dna[i].id = i;
		cin >> dna[i].seq;
		int cnt = 0;
		for (int p = 0; p < dna[i].seq.length() - 1; p++)
		{
			for (int q = p + 1; q < dna[i].seq.length(); q++)
			{
				if (dna[i].seq[p] > dna[i].seq[q])
					cnt++;
			}
		}
		dna[i].cnt = cnt;
	}
	sort(dna, dna + m, cmp);
	for (int i = 0; i < m; i++)
	{
		cout << dna[i].seq << endl;
	}
	return 0;
}

bool cmp(DNA a, DNA b)
{
	if (a.cnt > b.cnt)
		return 0;
	else if (a.cnt < b.cnt)
		return 1;
	else
	{
		if (a.id < b.id)
			return 1;
		else
			return 0;
	}
}