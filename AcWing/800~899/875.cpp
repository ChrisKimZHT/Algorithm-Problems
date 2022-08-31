#include <bits/stdc++.h>

using namespace std;

long long fast_pow(long long a, long long b, long long p)
{
    a %= p;
    long long ans = 1;
    while (b)
    {
        if (b % 2)
            ans = ans * a % p;
        a = a * a % p;
        b /= 2;
    }
    return ans;
}

int main()
{
    long long n;
    cin >> n;
    while (n--)
    {
        long long a, b, p;
        cin >> a >> b >> p;
        cout << fast_pow(a, b, p) << endl;
    }
    return 0;
}