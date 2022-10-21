#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
int N;
char A[MAXN][MAXN];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> A[i][j];
        getchar();
    }
    bool flag = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (A[i][j] == 'W' && A[j][i] != 'L' ||
                A[i][j] == 'L' && A[j][i] != 'W' ||
                A[i][j] == 'D' && A[j][i] != 'D')
            {
                flag = false;
                break;
            }
        }
        if (!flag)
            break;
    }
    if (flag)
        cout << "correct" << endl;
    else
        cout << "incorrect" << endl;
    return 0;
}