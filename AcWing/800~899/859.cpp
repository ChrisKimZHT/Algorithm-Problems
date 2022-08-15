#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10, INF = 0x3f3f3f3f;
int v, e;
int fa[MAXN];
struct Edge
{
    int start, end, dist;
    bool operator<(const Edge &x) const
    {
        return dist < x.dist;
    }
};
vector<Edge> edges;

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

int kruskal()
{
    sort(edges.begin(), edges.end());
    int ans = 0, selected = 0;
    bool flag = false;
    for (auto ed : edges)
    {
        if (find(ed.start) != find(ed.end))
        {
            merge(ed.start, ed.end);
            ans += ed.dist;
            if (++selected == v - 1)
            {
                flag = true;
                break;
            }
        }
    }
    return flag ? ans : INF;
}

int main(void)
{
    cin >> v >> e;
    init(v);
    for (int i = 0; i < e; i++)
    {
        int a, b, dis;
        cin >> a >> b >> dis;
        edges.push_back({a, b, dis});
    }
    int t = kruskal();
    if (t == INF)
        cout << "impossible" << endl;
    else
        cout << t << endl;
    return 0;
}