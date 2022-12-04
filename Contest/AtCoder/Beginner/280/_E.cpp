#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long ll;
const ll MOD = 998244353;
/* ll fastpow(ll a, ll b)
{
    a %= MOD;
    ll ans = 1;
    while (b)
    {
        if (b % 2 == 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}
inline ll inv(ll x)
{
    return fastpow(x, MOD - 2);
} */
const ll MAXN = 2e5 + 10;
ll dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll N, P;
    cin >> N >> P;
    // ll inv100 = inv(100);
    ll inv100 = 828542813;
    dp[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        dp[i] = P * inv100 % MOD * dp[i - 2] % MOD +
                (1 - (P * inv100 % MOD) + MOD) % MOD * dp[i - 1] % MOD + 1;
        dp[i] %= MOD;
    }
    cout << dp[N] << endl;
    return 0;
}