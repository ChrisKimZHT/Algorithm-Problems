#include <bits/stdc++.h>
#define E_SIZE 200010
#define V_SIZE 5010

using namespace std;

// 链式前向星模板
struct EDGE
{
    int to, weight, next;
} edge[E_SIZE * 2];
int head[V_SIZE];

int V, E;
int cnt;

void init()
{
    cnt = 0;
    for (int i = 1; i <= V; i++)
        head[i] = -1;
};

void add_edge(int start, int end, int weight)
{
    edge[cnt].to = end;
    edge[cnt].weight = weight;
    edge[cnt].next = head[start];
    head[start] = cnt++;
}

bool vis[V_SIZE];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;

int main(void)
{
    cin >> V >> E;
    init();
    for (int i = 0; i < E; i++)
    {
        int a, b, dis;
        cin >> a >> b >> dis;
        add_edge(a, b, dis);
        add_edge(b, a, dis);
    }
    int selected = -1, ans = 0;
    pque.push(make_pair(0, 1));
    while (!pque.empty() && selected != V - 1)
    {
        pair<int, int> tmp = pque.top();
        pque.pop();
        if (vis[tmp.second])
            continue;
        vis[tmp.second] = true;
        ans += tmp.first;
        selected++;
        for (int i = head[tmp.second]; i != -1; i = edge[i].next)
            pque.push(make_pair(edge[i].weight, edge[i].to));
    }
    if (selected == V - 1)
        cout << ans << endl;
    else
        cout << "orz" << endl;
    return 0;
}