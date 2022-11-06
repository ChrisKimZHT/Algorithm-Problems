#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int fa[MAXN], sz[MAXN];
inline void init()
{
    for (int i = 0; i < MAXN; i++)
    {
        fa[i] = i;
        sz[i] = 1;
    }
}
int find(int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}
inline void merge(int i, int j)
{
    if (find(i) == find(j))
        return;
    sz[find(j)] += sz[find(i)];
    fa[find(i)] = find(j);
}

int main()
{
    int a, b;
    init();
    int cnt = 1, size = 1;
    bool flag = true;
    while (cin >> a >> b, a != -1 || b != -1)
    {
        if (!a && !b)
        {
            // cout << cnt << ' ' << size << endl;
            if (flag && size == cnt)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            flag = true;
            cnt = size = 1;
            init();
            continue;
        }
        if (flag && find(a) == find(b))
            flag = false;
        if (flag)
        {
            merge(a, b);
            size = sz[find(a)];
            cnt++;
        }
    }
    return 0;
}