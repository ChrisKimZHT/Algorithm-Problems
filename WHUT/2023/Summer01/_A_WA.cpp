#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

const int MAXN = 2e5 + 10;
vector<int> edge[MAXN];
int effi[MAXN];

int dfs(int node)
{
    int ans = effi[node];
    if (edge[node].empty())
        return ans;
    priority_queue<int> pque;
    for (auto &ele : edge[node])
    {
        pque.push(dfs(ele));
    }
    while (pque.size() >= 2)
    {
        ans += pque.top();
        pque.pop();
        ans += pque.top();
        pque.pop();
    }
    if (pque.size() && pque.top() > effi[node])
        ans = ans - effi[node] + pque.top();
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int p, a;
        cin >> p >> a;
        effi[i] = a;
        if (p == -1)
            continue;
        edge[p].push_back(i);
    }
    cout << dfs(1) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}