#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30;
int n, k;
int x[MAXN];
bool vis[MAXN];
int ans = 0;

const int MAXM = 1e7 + 10;
int prime[MAXM], idx;
bool is_prime[MAXM];
void init_prime()
{
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAXM; i++)
    {
        if (is_prime[i])
            prime[idx++] = i;
        for (int j = 0; j < idx && i * prime[j] < MAXM; j++)
        {
            is_prime[i * prime[j]] = false;
            if (!(i % prime[j]))
                break;
        }
    }
}

void dfs(int dep, int sum, int sta)
{
    if (dep == k)
    {
        if (is_prime[sum])
            ans++;
        return;
    }
    for (int i = sta; i < n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            dfs(dep + 1, sum + x[i], i);
            vis[i] = false;
        }
    }
}

int main()
{
    init_prime();
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}