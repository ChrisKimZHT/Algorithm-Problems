#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int num[50][50];
    memset(num, 0, sizeof(num));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == N - 1)
            {
                num[i][j] = 1;
                cout << num[i][j] << ' ';
                continue;
            }
            num[i][j] = num[i - 1][j - 1] + num[i - 1][j];
            cout << num[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}