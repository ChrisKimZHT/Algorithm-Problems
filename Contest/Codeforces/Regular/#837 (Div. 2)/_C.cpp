#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 1e5 + 10;
int a[MAXN], prime[MAXN], primesize = 0;
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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, bool> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; prime[j] * prime[j] <= a[i]; j++)
        {
            if (!(a[i] % prime[j]))
            {
                if (mp[prime[j]])
                {
                    cout << "YES" << endl;
                    return;
                }
                else
                {
                    mp[prime[j]] = true;
                }
                while (!(a[i] % prime[j]))
                    a[i] /= prime[j];
            }
        }
        if (a[i] > 1)
        {
            if (mp[a[i]])
            {
                cout << "YES" << endl;
                return;
            }
            else
            {
                mp[a[i]] = true;
            }
        }
    }
    cout << "NO" << endl;
    return;
}

signed main()
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