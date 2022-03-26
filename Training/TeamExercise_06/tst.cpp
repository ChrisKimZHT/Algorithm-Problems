#include <bits/stdc++.h>
#define SIZE 1000

using namespace std;

struct EDGE
{
    int to, weight, next;
} edge[SIZE];
int head[SIZE];

int V, E; // E边数，V顶点数
int cnt;  // 储存边时的下标

void init()
{
    cnt = 0;
    // 全部初始化为-1
    for (int i = 1; i <= V; i++)
        head[i] = -1;
};

void add_edge(int start, int end, int weight)
{
    edge[cnt].to = end;           // 终点
    edge[cnt].weight = weight;    // 长度
    edge[cnt].next = head[start]; // 下一条边
    head[start] = cnt++;
}

void print()
{
    for (int i = 1; i <= V; ++i)
        for (int j = head[i]; j != -1; j = edge[j].next)
            cout << "Start = " << i << ", End = " << edge[j].to << ", Weight = " << edge[j].weight << endl;
}

int main()
{
    cin >> V >> E;
    init();
    // 输入边
    for (int i = 0; i < E; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        add_edge(a, b, w);
    }
    // 遍历全图
    print();
    return 0;
};