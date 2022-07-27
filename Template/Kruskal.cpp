#include <bits/stdc++.h>
#define SIZE 10000

using namespace std;

struct EDGE
{
    int start, end, dist; // start, end表示边的端点 dist表示边的长度
    // 构造函数
    EDGE(int a, int b, int c) : start(a), end(b), dist(c) {}
    // 重载<运算符供sort()排序
    bool operator<(const EDGE &x) const
    {
        return dist < x.dist;
    }
};

int V, E;          // E边数，V顶点数，S起点
vector<EDGE> edge; // 储存边
vector<EDGE> mst;  // 储存最小生成树

// 并查集模板，用于判环
int fa[SIZE];
inline void init(int n)
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}

int find(int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

inline void merge(int i, int j)
{
    fa[find(i)] = find(j);
}

int Kruskal()
{
    sort(edge.begin(), edge.end()); // 按边长排序
    int ans = 0, selected = 0;      // ans为答案，selected为已选边的条数
    bool flag = false;              // 是否存在最小生成树
    // 从小到大遍历边
    for (auto ed : edge)
    {
        // 若两点不会成环，则合并，并选择该边
        if (find(ed.start) != find(ed.end))
        {
            merge(ed.start, ed.end);
            mst.push_back(ed);
            ans += ed.dist;
            if (++selected == V - 1)
            {
                flag = true;
                break;
            }
        }
    }
    // 返回最小权值，若不存在最小生成数返回-1
    if (flag)
        return ans;
    else
        return -1;
}

int main(void)
{
    cout << "===============================" << endl
         << "实验26  最小生成树的 Kruskal 算法" << endl
         << "===============================" << endl;
    // 设置图的边数和顶点数
    cout << "输入图的顶点数：";
    cin >> V;
    cout << "输入图的边数：";
    cin >> E;
    // 并查集初始化
    init(V);
    // 读入边
    for (int i = 1; i <= E; i++)
    {
        cout << "输入第" << i << "条边的端点a、端点b、权重：";
        int a, b, dis;
        cin >> a >> b >> dis;
        edge.push_back(EDGE(a, b, dis));
    }
    // 输出最小生成树
    cout << "===============================" << endl;
    cout << "最小生成树权重为：" << Kruskal() << endl;
    for (auto e : mst)
    {
        cout << "V" << e.start << " <----" << e.dist << "----> V" << e.end << endl;
    }
    return 0;
}