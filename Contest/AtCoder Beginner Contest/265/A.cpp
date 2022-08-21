#include <bits/stdc++.h>

using namespace std;

int main()
{
    int X, Y, N;
    cin >> X >> Y >> N;
    if (Y < 3 * X)
        cout << N / 3 * Y + N % 3 * X << endl;
    else
        cout << N * X << endl;
    return 0;
}