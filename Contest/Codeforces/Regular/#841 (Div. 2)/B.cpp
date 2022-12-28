#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const long long MOD = 1e9 + 7;

long long fast_pow(long long a, long long b)
{
    a %= MOD;
    long long ans = 1;
    while (b)
    {
        if (b % 2 == 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

void solve()
{
    long long n;
    cin >> n;
    long long tmp = (((n * (n + 1)) % MOD * (n + 2)) % MOD * 333333336) % MOD;
    long long tmp2 = (((n * (n + 1)) % MOD * (2 * n + 1)) % MOD * 166666668) % MOD;
    long long tmp3 = (n * (n + 1)) % MOD;
    cout << ((((tmp + tmp2) % MOD - tmp3 + MOD) % MOD) * 2022) % MOD << endl;
}

int main()
{
    // cout << fast_pow(3, MOD - 2) << endl;
    // cout << fast_pow(6, MOD - 2) << endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}