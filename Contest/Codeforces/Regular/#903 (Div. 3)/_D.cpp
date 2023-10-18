// Problem: D. Divide and Equalize
// Contest: Codeforces - Codeforces Round 903 (Div. 3)
// URL: https://codeforces.com/contest/1881/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MAXN = 1e6 + 10;
int prime[MAXN], idx;
bool not_prime[MAXN];
int prime_id[MAXN];

void init_prime()
{
    not_prime[0] = not_prime[1] = true;
    for (int i = 2; i < MAXN; i++)
    {
        if (!not_prime[i])
        {
            prime_id[i] = idx;
            prime[idx++] = i;
        }
        for (int j = 0; j < idx && i * prime[j] < MAXN; j++)
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
    vector<int> cnt(idx);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        for (int j = 0; j < idx; j++)
        {
            while (t % prime[j] == 0)
            {
                t /= prime[j];
                cnt[j]++;
            }
            if (!not_prime[t])
            {
                cnt[prime_id[t]]++;
                break;
            }
            if (t == 1)
                break;
        }
    }
    for (int i = 0; i < idx; i++)
    {
        if (cnt[i] % n)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init_prime();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}