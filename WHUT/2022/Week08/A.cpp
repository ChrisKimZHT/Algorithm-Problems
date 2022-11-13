#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e6 + 3;
long long fact[MOD + 10];

void init()
{
    fact[0] = 1;
    for (int i = 1; i <= MOD; i++)
        fact[i] = fact[i - 1] * i % MOD;
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
    if (b > a)
        return 0;
    if (a < p && b < p)
        return fact[a] * inv(fact[b], p) % p * inv(fact[a - b], p) % p;
    return comb(a % p, b % p, p) * comb(a / p, b / p, p) % p;
}

int main()
{
    int n;
    cin >> n;
    init();
    while (n--)
    {
        long long N, L, R;
        cin >> N >> L >> R;
        cout << ((comb(N + (R - L + 1), R - L + 1, MOD) - 1) % MOD + MOD) % MOD << endl;
    }
    return 0;
}