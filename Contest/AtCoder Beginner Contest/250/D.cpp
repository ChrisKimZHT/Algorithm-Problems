#include <bits/stdc++.h>
#define SIZE 1000010

using namespace std;

int main()
{
    int prime[SIZE], primesize = 0;
    bool isprime[SIZE];
    memset(isprime, 1, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    for (int i = 2; i < SIZE; i++)
    {
        if (isprime[i])
            prime[primesize++] = i;
        for (int j = 0; j < primesize && i * prime[j] < SIZE; j++)
        {
            isprime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
    long long N;
    cin >> N;
    int ans = 0;
    for (int i = 0; i < primesize; i++)
    {
        if (1ll * prime[i] * prime[i + 1] * prime[i + 1] * prime[i + 1] > N)
            break;
        for (int j = i + 1; j < primesize; j++)
        {
            if (1ll * prime[i] * prime[j] * prime[j] * prime[j] <= N)
                ans++;
            else
                break;
        }
    }
    cout << ans << endl;
    return 0;
}