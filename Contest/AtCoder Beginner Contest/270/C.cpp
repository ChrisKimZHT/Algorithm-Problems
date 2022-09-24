#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
int N;
int X, Y;
vector<int> ed[MAXN];
bool vis[MAXN];
int prv[MAXN];

void add_edge(int a, int b)
{
    ed[a].push_back(b);
    ed[b].push_back(a);
}

queue<int> que;
void bfs(int src, int dest)
{
    que.push(src);
    vis[src] = true;
    while (que.size())
    {
        int now = que.front();
        que.pop();
        for (auto i : ed[now])
        {
            if (!vis[i])
            {
                vis[i] = true;
                prv[i] = now;
                que.push(i);
                if (i == dest)
                    return;
            }
        }
    }
}

int main()
{
    memset(prv, -1, sizeof(prv));
    cin >> N >> X >> Y;
    for (int i = 1; i < N; i++)
    {
        int U, V;
        cin >> U >> V;
        add_edge(U, V);
        add_edge(V, U);
    }
    bfs(X, Y);
    vector<int> ans;
    for (int i = Y; i != -1; i = prv[i])
        ans.push_back(i);
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}