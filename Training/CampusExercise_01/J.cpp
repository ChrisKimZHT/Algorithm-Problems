#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int A[110], B[110];
	int N, NA, NB;
	cin >> N >> NA >> NB;
	for (int i = 0; i < NA; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < NB; i++)
	{
		cin >> B[i];
	}
	int cntA = 0, cntB = 0;
	for (int i = 0; i < N; i++)
	{
		if (A[i % NA] == 0 && B[i % NB] == 2)
			cntA++;
		else if (A[i % NA] == 0 && B[i % NB] == 5)
			cntB++;
		else if (A[i % NA] == 2 && B[i % NB] == 5)
			cntA++;
		else if (A[i % NA] == 2 && B[i % NB] == 0)
			cntB++;
		else if (A[i % NA] == 5 && B[i % NB] == 0)
			cntA++;
		else if (A[i % NA] == 5 && B[i % NB] == 2)
			cntB++;
	}
	if (cntA > cntB)
		cout << "A" << endl;
	else if (cntA < cntB)
		cout << "B" << endl;
	else
		cout << "draw" << endl;
	return 0;
}