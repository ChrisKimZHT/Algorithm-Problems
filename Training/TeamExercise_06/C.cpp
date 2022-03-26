#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define SIZE 1000

using namespace std;

struct EDGE
{
    int start, end, dist;
    bool operator<(const EDGE &x) const
    {
        return dist < x.dist;
    }
} edge[SIZE * SIZE];

int pos = 0;

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

int main(void)
{
    int N;
    cin >> N;
    pair<int, int> node[SIZE];
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        node[i] = make_pair(x, y);
    }
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int dis = abs(node[i].first - node[j].first) + abs(node[i].second - node[j].second);
            edge[pos].start = i + 1;
            edge[pos].end = j + 1;
            edge[pos].dist = dis;
            pos++;
            edge[pos].start = j + 1;
            edge[pos].end = i + 1;
            edge[pos].dist = dis;
            pos++;
        }
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[pos].start = a;
        edge[pos].end = b;
        edge[pos].dist = 0;
        pos++;
        edge[pos].start = b;
        edge[pos].end = a;
        edge[pos].dist = 0;
        pos++;
    }
    init(N);
    sort(edge, edge + pos);
    for (int i = 0; i < pos; i++)
    {
        EDGE ed = edge[i];
        if (find(ed.start) != find(ed.end))
        {
            if (ed.dist)
                cout << ed.start << ' ' << ed.end << endl;
            merge(ed.start, ed.end);
        }
    }
    return 0;
}