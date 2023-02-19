#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MOD = 998244353, MAXA = 1e5 + 10;
long long fact[MAXA], invf[MAXA];

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
    return fast_pow(x, MOD - 2) % MOD;
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

long long comb(long long a, long long b)
{
    return fact[a] * invf[b] % MOD * invf[a - b] % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int n;
    cin >> n;
    long long ans = 1;
    for (int i = 0; i < n / 3; i++)
    {
        int w[3];
        cin >> w[0] >> w[1] >> w[2];
        sort(w, w + 3);
        if (w[0] == w[2])
            ans = (ans * 3) % MOD;
        else if (w[0] == w[1])
            ans = (ans * 2) % MOD;
    }
    ans = (ans * comb(n / 3, n / 6)) % MOD;
    cout << ans << endl;
    return 0;
}