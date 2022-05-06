#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1010;
int tri[SIZE][SIZE];

int main()
{
    int r;
    cin >> r;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cin >> tri[i][j];
        }
    }
    for (int i = r - 1; i >= 0; i--)
    {
        for (int j = 0; j < i + 1; j++)
        {
            tri[i][j] += max(tri[i + 1][j], tri[i + 1][j + 1]);
        }
    }
    cout << tri[0][0] << endl;
    return 0;
}