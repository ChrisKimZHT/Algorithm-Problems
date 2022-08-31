#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
int prime[MAXN], phi[MAXN], idx;
bool is_prime[MAXN];

void init(int n)
{
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            prime[idx++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < idx && i * prime[j] <= n; j++)
        {
            is_prime[i * prime[j]] = false;
            if (!(i % prime[j]))
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    init(n);
    cout << accumulate(phi + 1, phi + n + 1, 0LL) << endl;
    return 0;
}