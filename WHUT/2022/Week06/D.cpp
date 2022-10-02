#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
int fa[MAXN];
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
    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        for (int i = 1; i <= N; i++)
            fa[i] = i;
        while (M--)
        {
            int a, b;
            cin >> a >> b;
            merge(a, b);
        }
        int ans = 0;
        for (int i = 1; i <= N; i++)
            if (find(i) == i)
                ans++;
        cout << ans << endl;
    }
    return 0;
}