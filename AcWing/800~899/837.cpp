#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int fa[MAXN], sz[MAXN];
int n, m;

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        sz[i] = 1;
    }
}

int query(int x)
{
    return x == fa[x] ? x : (fa[x] = query(fa[x]));
}

int size(int x)
{
    return sz[query(x)];
}

void merge(int x, int y)
{
    if (query(x) == query(y))
        return;
    sz[query(y)] += sz[query(x)];
    fa[query(x)] = query(y);
}

int main()
{
    cin >> n >> m;
    init(n);
    while (m--)
    {
        char op[5];
        cin >> op;
        if (op[0] == 'C')
        {
            int a, b;
            cin >> a >> b;
            merge(a, b);
        }
        else if (op[1] == '1')
        {
            int a, b;
            cin >> a >> b;
            cout << (query(a) == query(b) ? "Yes" : "No") << endl;
        }
        else if (op[1] == '2')
        {
            int a;
            cin >> a;
            cout << size(a) << endl;
        }
    }
    return 0;
}