#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 1e5 + 10;
vector<int> edge[MAXN];

void dfs(int v, int h, vector<int> &dist)
{
    dist[v] = h;
    for (auto ele : edge[v])
        if (dist[ele] == -1)
            dfs(ele, h + 1, dist);
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    // init
    vector<int> dist_1(n + 10, -1);
    dfs(1, 0, dist_1);
    // farthest-a
    int max_1 = max_element(dist_1.begin(), dist_1.end()) - dist_1.begin();
    vector<int> dist_2(n + 10, -1);
    dfs(max_1, 0, dist_2);
    // farthest-b
    int max_2 = max_element(dist_2.begin(), dist_2.end()) - dist_2.begin();
    vector<int> dist_3(n + 10, -1);
    dfs(max_2, 0, dist_3);
    vector<int> dist(n + 10);
    for (int i = 1; i <= n; i++)
        dist[i] = max(dist_2[i], dist_3[i]);
    sort(dist.begin() + 1, dist.begin() + 1 + n);
    int single = 1;
    for (int i = 1; i <= n; i++)
    {
        while (single < n && dist[single] < i)
            single++;
        cout << single << ' ';
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}