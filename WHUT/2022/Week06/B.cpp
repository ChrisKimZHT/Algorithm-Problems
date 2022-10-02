#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

const int MAXN = 1010;
const double eps = 1e-9;
int N, d;
vector<pair<int, int>> cood;
vector<int> work;
int fa[MAXN];
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
inline bool dist(int a, int b)
{
    int dx = cood[a].first - cood[b].first;
    int dy = cood[a].second - cood[b].second;
    double ds = sqrt(dx * dx + dy * dy);
    return ds < d || fabs(ds - d) <= eps;
}

int main()
{
    cin >> N >> d;
    init(N);
    cood.push_back(make_pair(0, 0));
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        cood.push_back(make_pair(x, y));
    }
    char op;
    while (cin >> op)
    {
        if (op == 'O')
        {
            int t;
            cin >> t;
            for (int i = 0; i < work.size(); i++)
                if (find(work[i]) != find(t) && dist(work[i], t))
                    merge(work[i], t);
            work.push_back(t);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            if (find(a) == find(b))
                cout << "SUCCESS" << endl;
            else
                cout << "FAIL" << endl;
        }
        // getchar();
    }
    return 0;
}