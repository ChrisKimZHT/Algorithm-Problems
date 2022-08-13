/* #include <bits/stdc++.h>
#define SIZE 100010 // SIZE需比顶点数大

using namespace std;

struct NODE
{
    int dist, point; // dist储存起点到节点的距离，point为节点序号
    NODE(int first, int second)
    {
        point = first;
        dist = second;
    }
    // 重载<运算符，供优先队列排序使用
    bool operator<(const NODE &x) const
    {
        return dist > x.dist;
    }
};

int E, V, S;               // E边数，V顶点数，S起点
vector<NODE> edge[SIZE];   // 储存连接关系
priority_queue<NODE> pque; // 储存节点，节点距离小的在堆顶
int dist[SIZE];            // 储存节点距离
bool vis[SIZE];            // 是否已经访问过该节点的标志

void dijkstra(int src)
{
    // 初始化，设置距离为无穷大（用最大int表示）
    for (int i = 1; i <= V; i++)
        dist[i] = INT32_MAX;
    // 设置起点到起点的距离为0
    dist[src] = 0;
    // 起点入堆
    pque.push(NODE(src, dist[src]));
    while (!pque.empty())
    {
        // 取出堆顶节点
        NODE cur = pque.top();
        // 弹出堆顶节点
        pque.pop();
        // 如果该节点已经访问过，直接跳过
        if (vis[cur.point])
            continue;
        // 标记该节点已访问过
        vis[cur.point] = true;
        // 遍历与该节点相连的节点
        for (auto next : edge[cur.point])
        {
            // 如果src->cur->next的距离小于src->next的距离
            if (dist[cur.point] + next.dist < dist[next.point])
            {
                // 更新新距离
                dist[next.point] = dist[cur.point] + next.dist;
                // 如果next节点还未访问，则入堆
                if (!vis[next.point])
                    pque.push(NODE(next.point, dist[next.point]));
            }
        }
    }
}

int main(void)
{
    cin >> E >> V >> S;
    while (E--)
    {
        int a, b, dis;
        cin >> a >> b >> dis;
        edge[a].push_back(NODE(b, dis));
        // 若双向都能通过，添加 link[b].push_back(NODE(a, dis));
    }
    dijkstra(S);
    for (int i = 1; i <= V; i++)
        cout << dist[i] << ' ';
    return 0;
} */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
const int MAXN = 100010, INF = 0x3f3f3f3f;
int E, V, S;                                         // E边数，V顶点数，S起点
vector<PII> edge[MAXN];                              // 储存连接关系，二元组为(权值,终点)
priority_queue<PII, vector<PII>, greater<PII>> pque; // 储存节点，节点距离小的在堆顶
int dist[MAXN];                                      // 储存节点距离
bool vis[MAXN];                                      // 是否已经访问过该节点的标志

void dijkstra(int src)
{
    memset(dist, 0x3f, sizeof(dist));
    dist[src] = 0;
    pque.push({dist[src], src});
    while (!pque.empty())
    {
        PII cur = pque.top();
        pque.pop();
        if (vis[cur.second])
            continue;
        vis[cur.second] = true;
        for (auto next : edge[cur.second])
        {
            if (dist[cur.second] + next.first < dist[next.second])
            {
                dist[next.second] = dist[cur.second] + next.first;
                if (!vis[next.second])
                    pque.push({dist[next.second], next.second});
            }
        }
    }
}

int main(void)
{
    cin >> E >> V >> S;
    while (E--)
    {
        int a, b, dis;
        cin >> a >> b >> dis;
        edge[a].push_back({dis, b});
    }
    dijkstra(S);
    for (int i = 1; i <= V; i++)
        cout << dist[i] << ' ';
    return 0;
}
