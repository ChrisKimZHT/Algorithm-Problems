#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int fa[MAXN];
int n, m;

void init(int n)
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}

int query(int x)
{
    return x == fa[x] ? x : (fa[x] = query(fa[x]));
}

void merge(int x, int y)
{
    fa[query(x)] = query(y);
}

int main()
{
    cin >> n >> m;
    init(n);
    while (m--)
    {
        char op;
        cin >> op;
        if (op == 'M')
        {
            int a, b;
            cin >> a >> b;
            merge(a, b);
        }
        else if (op == 'Q')
        {
            int a, b;
            cin >> a >> b;
            cout << (query(a) == query(b) ? "Yes" : "No") << endl;
        }
    }
    return 0;
}