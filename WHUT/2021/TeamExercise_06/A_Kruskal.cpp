#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct EDGE
{
    int start, end, dist;
    bool vis;
    EDGE(int a, int b, int c)
    {
        start = a;
        end = b;
        dist = c;
        vis = false;
    }
    bool operator<(const EDGE &x) const
    {
        return dist < x.dist;
    }
};

int fa[100000];

int find(int x)
{
    if (fa[x] == x)
        return x;
    else
        return find(fa[x]);
}

void merge(int i, int j)
{
    fa[find(i)] = find(j);
}

int main(void)
{
    int P, R;
    vector<EDGE> edge;
    while (cin >> P && P)
    {
        cin >> R;
        for (int i = 0; i < R; i++)
        {
            int a, b, dis;
            cin >> a >> b >> dis;
            edge.push_back(EDGE(a, b, dis));
        }
        sort(edge.begin(), edge.end());
        for (int i = 1; i <= P; i++)
        {
            fa[i] = i;
        }
        int ans = 0;
        // for (auto ed : edge)
        for (int i = 0; i < edge.size(); i++)
        {
            EDGE ed = edge[i];
            if (!ed.vis && find(ed.start) != find(ed.end))
            {
                merge(ed.start, ed.end);
                ans += ed.dist;
                ed.vis = true;
            }
        }
        cout << ans << endl;
        edge.clear();
    }
    return 0;
}