#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long ll;
const int MAXN = 1e6 + 10;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init_prime();
    ll K;
    cin >> K;
    ll ans = 0;
    for (int i = 0; i < primesize; i++)
    {
        ll prm = prime[i], cnt = 0;
        if (prm * prm > K)
            break;
        while (!(K % prm))
        {
            K /= prm;
            cnt++;
        }
        ll n = 0;
        while (cnt > 0)
        {
            n += prm;
            int x = n;
            while (!(x % prm))
            {
                x /= prm;
                cnt--;
            }
        }
        ans = max(ans, n);
    }
    cout << max(ans, K) << endl;
    return 0;
}