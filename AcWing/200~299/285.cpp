#include <bits/stdc++.h>

using namespace std;

const int MAXN = 6010;
int N;
int happy[MAXN];
int h[MAXN], e[MAXN], ne[MAXN], idx;
bool not_root[MAXN];
int dp[MAXN][2];

inline void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int n)
{
    dp[n][1] = happy[n];
    for (int i = h[n]; i != -1; i = ne[i])
    {
        dfs(e[i]);
        dp[n][0] += max(dp[e[i]][1], dp[e[i]][0]);
        dp[n][1] += dp[e[i]][0];
    }
}

int main()
{
    memset(h, -1, sizeof(h));
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> happy[i];
    for (int i = 1; i < N; i++)
    {
        int L, K;
        cin >> L >> K;
        not_root[L] = true;
        add(K, L);
    }
    int root = 1;
    while (not_root[root])
        root++;
    dfs(root);
    cout << max(dp[root][0], dp[root][1]) << endl;
    return 0;
}