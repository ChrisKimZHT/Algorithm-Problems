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
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; prime[j] * prime[j] <= a[i]; j++)
        {
            if (!(a[i] % prime[j]))
            {
                if (s.find(prime[j]) != s.end())
                {
                    cout << "YES" << endl;
                    return;
                }
                s.insert(prime[j]);
                while (!(a[i] % prime[j]))
                    a[i] /= prime[j];
            }
        }
        if (a[i] > 1)
        {
            if (s.find(a[i]) != s.end())
            {
                cout << "YES" << endl;
                return;
            }
            s.insert(a[i]);
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