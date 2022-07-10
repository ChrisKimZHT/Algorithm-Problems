#include <bits/stdc++.h>

using namespace std;

long long fast_pow(long long a, long long b)
{
    long long res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    cout << fast_pow(2, N) << endl;
    return 0;
}