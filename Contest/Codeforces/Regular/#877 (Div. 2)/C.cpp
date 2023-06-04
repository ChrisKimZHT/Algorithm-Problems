#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    int now = 1;
    if (not_prime[n])
    {
        for (int i = 0; i < m; i += 2)
            for (int j = 0; j < n; j++)
                mat[j][i] = now++;
        for (int i = 1; i < m; i += 2)
            for (int j = 0; j < n; j++)
                mat[j][i] = now++;
    }
    else if (not_prime[m])
    {
        for (int i = 0; i < n; i += 2)
            for (int j = 0; j < m; j++)
                mat[i][j] = now++;
        for (int i = 1; i < n; i += 2)
            for (int j = 0; j < m; j++)
                mat[i][j] = now++;
    }
    else
    {
        for (int i = 0; i < n; i += 3)
            for (int j = 0; j < m; j++)
                mat[i][j] = now++;
        for (int i = 1; i < n; i += 3)
            for (int j = 0; j < m; j++)
                mat[i][j] = now++;
        for (int i = 2; i < n; i += 3)
            for (int j = 0; j < m; j++)
                mat[i][j] = now++;
    }
    for (auto &x : mat)
    {
        for (auto &y : x)
            cout << y << ' ';
        cout << endl;
    }
}

signed main()
{
    init_prime();
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}