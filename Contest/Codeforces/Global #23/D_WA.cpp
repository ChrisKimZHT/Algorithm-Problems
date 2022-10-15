#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 2e5 + 10;
vector<int> son[MAXN];
int s[MAXN];

bool cmp(pair<int, pair<int, bool>> a, pair<int, pair<int, bool>> b)
{
    return a.first > b.first;
}

int dfs(int x, int n)
{
    if (!son[x].size())
        return n * s[x];
    int k = n / son[x].size();
    int p = n % son[x].size();
    vector<pair<int, pair<int, bool>>> ans;
    for (int i = 0; i < son[x].size(); i++)
    {
        ans.push_back({dfs(son[x][i], k), {i, false}});
        ans.push_back({dfs(son[x][i], k + 1), {i, true}});
    }
    sort(ans.begin(), ans.end(), cmp);
    vector<bool> vis(son[x].size());
    int res = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        int node = ans[i].second.first;
        if (!vis[node])
        {
            if (p > 0)
            {
                vis[node] = true;
                res += ans[i].first;
                p--;
            }
            else if (!ans[i].second.second)
            {
                vis[node] = true;
                res += ans[i].first;
            }
        }
    }
    res += n * s[x];
    return res;
}

void solve()
{
    for (int i = 0; i < MAXN; i++)
        son[i].clear();
    int n, k;
    cin >> n >> k;
    for (int i = 2; i <= n; i++)
    {
        int t;
        cin >> t;
        son[t].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    int ans = dfs(1, k);
    cout << ans << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}