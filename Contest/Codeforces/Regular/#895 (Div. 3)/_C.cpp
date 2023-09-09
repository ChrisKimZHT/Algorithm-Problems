// Problem: C. Non-coprime Split
// Contest: Codeforces - Codeforces Round 895 (Div. 3)
// URL: https://codeforces.com/contest/1872/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

constexpr int MAXN = 1e7 + 10;
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
}

void solve()
{
    int l, r;
    cin >> l >> r;
    int ans = -1;
    for (int i = max(2, l); i <= r; i++)
    {
    	if (not_prime[i])
    	{
    		ans = i;
    		break;
    	}
    }
    if (ans == -1)
    {
    	cout << -1 << endl;
    	return;
    }
    for (int i = 2; i * i <= ans; i++)
    {
    	if (ans % i == 0)
    	{
    		int t = ans / i;
    		cout << t << ' ' << (i - 1) * t << endl;
    		return;
    	}
    }
    cout << -1 << endl;
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