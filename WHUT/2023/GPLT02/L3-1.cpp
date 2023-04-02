#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 550;
vector<vector<pair<int, int>>> edge_dis(MAXN);
vector<vector<pair<int, int>>> edge_time(MAXN);
random_device rd;
mt19937 r_eng(rd());
uniform_int_distribution<int> ds(0, 1);

pair<int, vector<int>>
bfs(vector<vector<pair<int, int>>> &edge,
    vector<vector<pair<int, int>>> &edge_sub,
    int src, int end, bool type)
{
    vector<int> dis(MAXN, INT32_MAX);
    vector<int> dis_sub(MAXN, INT32_MAX);
    vector<int> lst(MAXN);
    queue<int> que;
    que.push(src);
    dis[src] = 0;
    lst[src] = -1;
    while (que.size())
    {
        int now = que.front();
        que.pop();
        for (int i = 0; i < edge[now].size(); i++)
        {
            auto nxt_node = edge[now][i];
            auto nxt_node_sub = edge_sub[now][i];
            int nxt = nxt_node.first;
            int new_dist = dis[now] + nxt_node.second;
            int new_dist_sub = dis_sub[now] + nxt_node_sub.second;
            if (new_dist < dis[nxt])
            {
                dis[nxt] = new_dist;
                dis_sub[nxt] = new_dist_sub;
                que.push(nxt);
                lst[nxt] = now;
            }
            else if ((!type || ds(r_eng)) && new_dist == dis[nxt] && new_dist_sub < dis_sub[nxt])
            {
                dis[nxt] = new_dist;
                dis_sub[nxt] = new_dist_sub;
                que.push(nxt);
                lst[nxt] = now;
            }
        }
    }
    vector<int> ans;
    for (int i = end; i != -1; i = lst[i])
        ans.push_back(i);
    reverse(ans.begin(), ans.end());
    return {dis[end], ans};
}

void solve()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        edge_dis[a].push_back({b, d});
        edge_time[a].push_back({b, e});
        if (c == 0)
        {
            edge_dis[b].push_back({a, d});
            edge_time[b].push_back({a, e});
        }
    }
    int src, end;
    cin >> src >> end;
    pair<int, vector<int>> ans_dis = bfs(edge_dis, edge_time, src, end, true);
    pair<int, vector<int>> ans_time = bfs(edge_time, edge_dis, src, end, false);
    if (ans_dis.second == ans_time.second)
    {
        cout << "Time = " << ans_time.first << "; Distance = " << ans_dis.first << ": ";
        bool flag = false;
        for (auto ele : ans_dis.second)
        {
            if (flag)
                cout << " => ";
            flag = true;
            cout << ele;
        }
        cout << endl;
        return;
    }
    cout << "Time = " << ans_time.first << ": ";
    bool flag = false;
    for (auto ele : ans_time.second)
    {
        if (flag)
            cout << " => ";
        flag = true;
        cout << ele;
    }
    cout << endl;
    cout << "Distance = " << ans_dis.first << ": ";
    flag = false;
    for (auto ele : ans_dis.second)
    {
        if (flag)
            cout << " => ";
        flag = true;
        cout << ele;
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