#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;
int N, P;
int square[4];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;
        square[0]++;
        for (int j = 3; j >= 0; j--)
        {
            if (square[j])
            {
                if (j + A <= 3)
                {
                    square[j + A]++;
                    square[j]--;
                }
                else
                {
                    square[j]--;
                    P++;
                }
            }
        }
    }
    cout << P << endl;
    return 0;
}