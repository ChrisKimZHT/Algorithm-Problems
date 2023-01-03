#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 998244353, MAXN = 3e5 + 10;
bool not_prime[MAXN];
int prime[MAXN], idx;
void init_prime()
{
    not_prime[0] = not_prime[1] = true;
    for (int i = 2; i < MAXN; i++)
    {
        if (!not_prime[i])
            prime[idx++] = i;
        for (int j = 0; j < idx && prime[j] * i < MAXN; j++)
        {
            not_prime[prime[j] * i] = true;
            if (!(i % prime[j]))
                break;
        }
    }
}

int main()
{
    init_prime();
    ll n, m;
    cin >> n >> m;
    ll ans = 0, cnt = 1, prime_mul = 1;
    for (ll i = 1; i <= n; i++)
    {
        if (!not_prime[i])
            prime_mul *= i;
        if (prime_mul > m)
            break;
        cnt = cnt * (m / prime_mul % MOD) % MOD;
        ans = (ans + cnt) % MOD;
    }
    ll all = 0, pow_m = 1;
    for (ll i = 1; i <= n; i++)
    {
        pow_m = pow_m * (m % MOD) % MOD;
        all = (all + pow_m) % MOD;
    }
    cout << (all - ans + MOD) % MOD << endl;
    return 0;
}