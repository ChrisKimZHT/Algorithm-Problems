#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int fa[MAXN], ds[MAXN];
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

void merge(int a, int b)
{
    int faa = find(a), fab = find(b);
    fa[faa] = fab;
    ds[faa] = ds[b] - ds[a] + 1;
}

int main()
{
    int N;
    cin >> N;
    init(N);
    for (int i = 2; i <= N; i++)
    {
        int t;
        cin >> t;
        merge(i, t);
    }
    cout << ds[N] << endl;
    return 0;
}