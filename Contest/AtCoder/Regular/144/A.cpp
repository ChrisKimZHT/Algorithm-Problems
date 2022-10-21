#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    cout << 2 * N << endl;
    if (N % 4)
        cout << N % 4;
    for (int i = 0; i < N / 4; i++)
        cout << 4;
    cout << endl;
    return 0;
}