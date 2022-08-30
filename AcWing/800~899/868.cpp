#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
int n, prime[MAXN], idx;
bool is_prime[MAXN];

int main()
{
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
            prime[idx++] = i;
        for (int j = 0; j < idx && prime[j] * i <= n; j++)
        {
            is_prime[prime[j] * i] = false;
            if (!(i % prime[j]))
                break;
        }
    }
    cout << idx << endl;
    return 0;
}