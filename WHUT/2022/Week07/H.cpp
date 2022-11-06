#include <bits/stdc++.h>

using namespace std;

const long long MAXA = 1e7 + 10, MOD = 1e9 + 7;
long long fact[MAXA];

void init(int mod)
{
    fact[0] = 1;
    for (int i = 1; i < MAXA; i++)
        fact[i] = fact[i - 1] * i % mod;
}

long long fast_pow(long long a, long long b, long long p)
{
    b %= p;
    long long ans = 1;
    while (b)
    {
        if (b % 2)
            ans = a * ans % p;
        a = a * a % p;
        b /= 2;
    }
    return ans;
}

inline long long inv(long long x, long long p)
{
    return fast_pow(x, p - 2, p);
}

long long comb(long long a, long long b, long long p)
{
    if (a < p && b < p)
    {
        return fact[a] * inv(fact[b], p) % p * inv(fact[a - b], p) % p;
    }
    return comb(a % p, b % p, p) * comb(a / p, b / p, p) % p;
}

int main()
{
    init(MOD);
    long long m, n;
    cin >> m >> n;
    cout << comb(n + m - 2, m - 1, MOD) << endl;
    return 0;
}