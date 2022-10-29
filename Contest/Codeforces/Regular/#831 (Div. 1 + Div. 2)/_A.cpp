#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
int prime[MAXN], idx;
bool not_prime[MAXN];
void init_prime()
{
    not_prime[0] = not_prime[1] = true;
    for (int i = 2; i < MAXN; i++)
    {
        if (!not_prime[i])
            prime[idx++] = i;
        for (int j = 0; j < idx && i * prime[j] < MAXN; j++)
        {
            not_prime[i * prime[j]] = true;
            if (!(i % prime[j]))
                break;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < idx; i++)
    {
        if (not_prime[n + prime[i]])
        {
            cout << prime[i] << endl;
            return;
        }
    }
}

int main()
{
    init_prime();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}