#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e4 + 10;
int fa[MAXN];
inline void init(int n)
{
    for (int i = 0; i < n; i++)
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

int n, m;

int main()
{
    while (cin >> n >> m, n || m)
    {
        init(n);
        while (m--)
        {
            int cnt;
            cin >> cnt;
            cnt--;
            int root;
            cin >> root;
            while (cnt--)
            {
                int t;
                cin >> t;
                merge(root, t);
            }
        }
        int sus = find(0), ans = 0;
        for (int i = 0; i < n; i++)
            if (find(i) == sus)
                ans++;
        cout << ans << endl;
    }
    return 0;
}