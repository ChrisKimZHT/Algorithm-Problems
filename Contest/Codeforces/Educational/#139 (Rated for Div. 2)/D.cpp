#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 1e4;
int prime[MAXN], primesize = 0;
bool not_prime[MAXN];
void init_prime()
{
    not_prime[0] = not_prime[1] = true;
    for (int i = 2; i < MAXN; i++)
    {
        if (!not_prime[i])
            prime[primesize++] = i;
        for (int j = 0; j < primesize && i * prime[j] < MAXN; j++)
        {
            not_prime[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

void solve()
{
    int x, y;
    cin >> x >> y;
    if (y - x == 1)
    {
        cout << -1 << endl;
        return;
    }
    if (x != 1 && !(y % x))
    {
        cout << 0 << endl;
        return;
    }
    int delta = y - x;
    vector<int> factor;
    for (int i = 0; prime[i] * prime[i] <= delta; i++)
    {
        while (!(delta % prime[i]))
        {
            delta /= prime[i];
            factor.push_back(prime[i]);
        }
    }
    if (delta > 1)
        factor.push_back(delta);
    int fact_size = factor.size(), ans = INT32_MAX;
    for (int i = 1; i < 1 << fact_size; i++)
    {
        int num = 1;
        for (int j = 0; j < fact_size; j++)
            if (i >> j & 1)
                num *= factor[j];
        int nx = ((x - 1) / num + 1) * num;
        ans = min(ans, nx - x);
    }
    cout << ans << endl;
}

int main()
{
    init_prime();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}