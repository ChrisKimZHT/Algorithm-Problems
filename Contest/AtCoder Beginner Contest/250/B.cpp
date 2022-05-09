#include <bits/stdc++.h>

using namespace std;

int N, A, B;
bool mp[120][120];

int main()
{
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if ((i + j) % 2 == 0)
                continue;
            for (int k = 0; k < A; k++)
            {
                for (int l = 0; l < B; l++)
                {
                    mp[i * A + k][j * B + l] = true;
                }
            }
        }
    }
    for (int i = 0; i < A * N; i++)
    {
        for (int j = 0; j < B * N; j++)
        {
            if (mp[i][j])
                cout << '#';
            else
                cout << '.';
        }
        cout << endl;
    }
    return 0;
}