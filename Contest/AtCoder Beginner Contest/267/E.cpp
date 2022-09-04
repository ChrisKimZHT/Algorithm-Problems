#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
int N, M, A[MAXN];
vector<int> edges[MAXN];
long long _cost[MAXN], cost[MAXN];
bool vis[MAXN];

bool vaild(long long x)
{
    memcpy(cost, _cost, sizeof(cost));
    memset(vis, 0, sizeof(vis));
    stack<int> stk; // queue is ok too
    for (int i = 1; i <= N; i++)
        if (cost[i] <= x)
            stk.push(i);
    while (stk.size())
    {
        int t = stk.top();
        stk.pop();
        if (vis[t])
            continue;
        vis[t] = true;
        for (auto d : edges[t])
        {
            if (!vis[d])
            {
                cost[d] -= A[t];
                if (cost[d] <= x)
                    stk.push(d);
            }
        }
    }
    for (int i = 1; i <= N; i++)
        if (!vis[i])
            return false;
    return true;
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        _cost[u] += A[v];
        edges[v].push_back(u);
        _cost[v] += A[u];
    }
    long long l = 0, r = INT64_MAX;
    while (l < r)
    {
        long long mid = (l + r) / 2;
        if (vaild(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}