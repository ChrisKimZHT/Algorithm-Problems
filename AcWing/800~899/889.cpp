#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

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

int main()
{
    long long n;
    cin >> n;
    long long ans = 1;
    for (int i = 2 * n; i > n; i--)
        ans = ans * i % MOD;
    for (int i = 1; i <= n; i++)
        ans = ans * fast_pow(i, MOD - 2) % MOD;
    ans = ans * fast_pow(n + 1, MOD - 2) % MOD;
    cout << ans << endl;
    return 0;
}