#include <bits/stdc++.h>

using namespace std;

const int MAXA = 1e5 + 10;
const long long MOD = 1e9 + 7;
long long fact[MAXA];
int n;

void init()
{
    fact[0] = 1;
    for (int i = 1; i < MAXA; i++)
        fact[i] = fact[i - 1] * i % MOD;
}

long long fast_pow(long long a, long long b)
{
    b %= MOD;
    long long ans = 1;
    while (b)
    {
        if (b % 2)
            ans = a * ans % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return ans;
}

inline long long inv(long long x)
{
    return fast_pow(x, MOD - 2);
}

int main()
{
    init();
    cin >> n;
    while (n--)
    {
        long long a, b;
        cin >> a >> b;
        cout << fact[a] * inv(fact[b]) % MOD * inv(fact[a - b]) % MOD << endl;
    }
    return 0;
}

/* #include <bits/stdc++.h>

using namespace std;

const int MAXA = 1e5 + 10;
const long long MOD = 1e9 + 7;
long long fact[MAXA], invf[MAXA];
int n;

long long fast_pow(long long a, long long b)
{
    b %= MOD;
    long long ans = 1;
    while (b)
    {
        if (b % 2)
            ans = a * ans % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return ans;
}

inline long long inv(long long x)
{
    return fast_pow(x, MOD - 2);
}

void init()
{
    fact[0] = invf[0] = 1;
    for (int i = 1; i < MAXA; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = invf[i - 1] * inv(i) % MOD;
    }
}

int main()
{
    init();
    cin >> n;
    while (n--)
    {
        long long a, b;
        cin >> a >> b;
        cout << fact[a] * invf[b] % MOD * invf[a - b] % MOD << endl;
    }
    return 0;
} */