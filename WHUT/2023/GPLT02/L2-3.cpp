#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 1000;
vector<int> edge[MAXN];
vector<int> mid, pre;

void construct_tree(int ms, int me, int ps, int pe, int fa)
{
    if (ms > me || ps > pe)
        return;
    int root = pre[ps];
    edge[fa].push_back(root);
    int root_in_mid = find(mid.begin(), mid.end(), root) - mid.begin();
    int l_ms = ms, l_me = root_in_mid - 1;
    int l_ps = ps + 1, l_pe = ps + 1 + l_me - l_ms;
    int r_ms = root_in_mid + 1, r_me = me;
    int r_ps = l_pe + 1, r_pe = pe;
    construct_tree(r_ms, r_me, r_ps, r_pe, root);
    construct_tree(l_ms, l_me, l_ps, l_pe, root);
}

void output_tree()
{
    queue<int> que;
    que.push(edge[0].front());
    bool flag = false;
    while (que.size())
    {
        int now = que.front();
        que.pop();
        if (flag)
            cout << ' ';
        flag = true;
        cout << now;
        for (auto nxt : edge[now])
            que.push(nxt);
    }
    cout << endl;
}

void solve()
{
    int N;
    cin >> N;
    mid.resize(N + 10);
    pre.resize(N + 10);
    for (int i = 1; i <= N; i++)
        cin >> mid[i];
    for (int i = 1; i <= N; i++)
        cin >> pre[i];
    construct_tree(1, N, 1, N, 0);
    output_tree();
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}