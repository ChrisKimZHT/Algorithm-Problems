#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

constexpr int MAXN = 1e6 + 10;
int prime[MAXN], prime_size;
bool not_prime[MAXN];

void init_prime()
{
    not_prime[0] = not_prime[1] = true;
    for (int i = 2; i < MAXN; i++)
    {
        if (!not_prime[i])
            prime[prime_size++] = i;
        for (int j = 0; j < prime_size && i * prime[j] < MAXN; j++)
        {
            not_prime[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
    // for (int i = 0; i < 100; i++)
    //     cout << prime[i] << ' ';
    // cout << endl;
}

void solve(int n)
{
    for (int i = 0; i < prime_size; i++)
    {
        if (!not_prime[n - prime[i]])
        {
            cout << n << " = " << prime[i] << " + " << n - prime[i] << endl;
            return;
        }
    }
    cout << "Goldbach's conjecture is wrong." << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init_prime();
    int n;
    while (cin >> n, n)
        solve(n);
    return 0;
}