#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int fa[MAXN + 10];
inline void init()
{
    for (int i = 1; i <= MAXN; i++)
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

int main()
{
    int a, b;
    init();
    bool flag = true;
    while (cin >> a >> b, a != -1 || b != -1)
    {
        if (!a && !b)
        {
            if (flag)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            flag = true;
            init();
            continue;
        }
        if (flag && find(a) == find(b))
            flag = false;
        if (flag)
            merge(a, b);
    }
    return 0;
}