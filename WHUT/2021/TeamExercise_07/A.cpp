#include <bits/stdc++.h>
#define SIZE 100010

using namespace std;

vector<int> edge[SIZE];
vector<int> white, black;
queue<int> que;
int color[SIZE];
bool flag = true;

void bfs(int x)
{
    que.push(x);
    if (color[x] == -1)
        color[x] = true;
    black.push_back(x);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (auto next : edge[now])
        {
            if (color[next] == -1)
            {
                color[next] = !color[now];
                if (color[next])
                {
                    black.push_back(next);
                }
                else
                {
                    white.push_back(next);
                }
                que.push(next);
            }
            else if (color[next] == !color[now])
            {
                continue;
            }
            else
            {
                flag = false;
            }
        }
    }
}

int main(void)
{
    memset(color, -1, sizeof(color));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!flag)
            break;
        if (color[i] == -1)
            bfs(i);
    }
    if (flag)
    {
        cout << white.size() << endl;
        for (auto i : white)
            cout << i << ' ';
        cout << endl;
        cout << black.size() << endl;
        for (auto i : black)
            cout << i << ' ';
        cout << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
    return 0;
}