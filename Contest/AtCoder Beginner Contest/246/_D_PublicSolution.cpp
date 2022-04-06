#include <bits/stdc++.h>

using namespace std;

long long f(long long a, long long b)
{
    return (a * a * a + a * a * b + a * b * b + b * b * b);
}

int main()
{
    long long n;
    cin >> n;
    long long x = 8e18;
    long long j = 1000000;
    for (long long i = 0; i <= 1000000; i++)
    {
        while (f(i, j) >= n && j >= 0)
        {
            x = min(x, f(i, j));
            j--;
        }
    }
    cout << x << '\n';
    return 0;
}
