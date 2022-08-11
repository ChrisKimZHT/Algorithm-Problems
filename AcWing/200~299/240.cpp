#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e4 + 10;
int N, K;
int fa[MAXN], ds[MAXN];
int ans;

inline void init(int n)
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}

int find(int n)
{
    if (fa[n] == n)
        return n;
    int res = find(fa[n]);
    ds[n] += ds[fa[n]];
    return fa[n] = res;
}

void merge(int a, int b, int r)
{
    int faa = find(a), fab = find(b);
    fa[faa] = fab;
    ds[faa] = ds[b] - ds[a] + r;
    // 血的教训
    // fa[find(a)] = find(b);
    // ds[find(a)] = ds[b] - ds[a] + r;
}

int main()
{
    cin >> N >> K;
    init(N);
    while (K--)
    {
        int D, X, Y;
        cin >> D >> X >> Y;
        if (X > N || Y > N)
        {
            ans++;
            continue;
        }
        if (D == 2 && X == Y)
        {
            ans++;
            continue;
        }
        if (find(X) == find(Y))
        {
            if (((ds[X] - ds[Y]) % 3 + 3) % 3 != D - 1)
                ans++;
        }
        else
        {
            merge(X, Y, D - 1);
        }
    }
    cout << ans << endl;
    return 0;
}