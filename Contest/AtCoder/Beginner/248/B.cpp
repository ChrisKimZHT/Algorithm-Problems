#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long A, B, K;
    cin >> A >> B >> K;
    int i;
    for (i = 0; A < B; i++)
        A *= K;
    cout << i << endl;
    return 0;
}