#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 998244353;
const int MAXN = 2e5 + 10;
int fact[MAXN], invf[MAXN];

int fast_pow(int a, int b)
{
    a %= MOD;
    int ans = 1;
    while (b)
    {
        if (b % 2 == 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

void fact_init()
{
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        fact[i] = fact[i - 1] * i % MOD;
    for (int i = 0; i <= MAXN; i++)
        invf[i] = fast_pow(fact[i], MOD - 2);
}

int comb(int n, int m)
{
    return ((fact[n] * invf[m]) % MOD * invf[n - m]) % MOD;
}

signed main()
{
    fact_init();
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> d(N);
    for (int i = 0; i < M; i++)
    {
        int U, V;
        cin >> U >> V;
        d[U - 1]++;
        d[V - 1]++;
    }
    int odd = 0;
    for (auto x : d)
        if (x % 2)
            odd++;
    int even = N - odd;
    long long ans = 0;
    for (int selected_odd = 0; selected_odd <= K; selected_odd += 2)
    {
        int selected_even = K - selected_odd;
        if (selected_odd <= odd && selected_even <= even)
        {
            ans += comb(odd, selected_odd) * comb(even, selected_even);
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}