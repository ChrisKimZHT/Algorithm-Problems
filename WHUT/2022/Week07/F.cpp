#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e6 + 10;
int prime[MAXN], euler[MAXN], presum[MAXN], idx;
bool not_prime[MAXN];
void init()
{
    euler[1] = 1;
    not_prime[0] = not_prime[1] = true;
    for (int i = 2; i < MAXN; i++)
    {
        if (!not_prime[i])
        {
            prime[idx++] = i;
            euler[i] = i - 1;
        }
        for (int j = 0; j < idx && prime[j] * i < MAXN; j++)
        {
            not_prime[i * prime[j]] = true;
            if (!(i % prime[j]))
            {
                euler[i * prime[j]] = euler[i] * prime[j];
                break;
            }
            euler[i * prime[j]] = euler[i] * (prime[j] - 1);
        }
    }
    for (int i = 2; i < MAXN; i++)
        presum[i] = presum[i - 1] + euler[i];
}

signed main()
{
    init();
    int n;
    while (cin >> n, n)
        cout << presum[n] << endl;
    return 0;
}