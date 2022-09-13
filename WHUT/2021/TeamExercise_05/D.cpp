#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INT32_MAX 2147483647
#define SIZE 1010

using namespace std;

struct NODE
{
    int P, T;
    NODE(int a, int b)
    {
        P = a;
        T = b;
    }
    bool operator<(const NODE &x) const
    {
        return T > x.T;
    }
};

int N, M, X; // N个农场，M个路，X为终点
vector<NODE> edge[SIZE];
priority_queue<NODE> pque;
int time[SIZE];
bool vis[SIZE];
int sum_time[SIZE];

void dijkstra(int src)
{
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= N; i++)
    {
        time[i] = INT32_MAX;
    }
    time[src] = 0;
    pque.push(NODE(src, time[src]));
    while (!pque.empty())
    {
        NODE cur = pque.top();
        pque.pop();
        if (vis[cur.P])
            continue;
        vis[cur.P] = true;
        for (int i = 0; i < edge[cur.P].size(); i++)
        {
            NODE next = edge[cur.P][i];
            if (time[cur.P] + next.T < time[next.P])
            {
                time[next.P] = time[cur.P] + next.T;
                if (!vis[next.P])
                {
                    pque.push(NODE(next.P, time[next.P]));
                }
            }
        }
    }
}

int main(void)
{
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++)
    {
        int A, B, T;
        cin >> A >> B >> T;
        edge[A].push_back(NODE(B, T));
    }
    for (int i = 1; i <= N; i++)
    {
        dijkstra(i);
        sum_time[i] += time[X];
    }
    dijkstra(X);
    for (int i = 1; i <= N; i++)
    {
        sum_time[i] += time[i];
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans = max(ans, sum_time[i]);
    }
    cout << ans << endl;
    return 0;
}