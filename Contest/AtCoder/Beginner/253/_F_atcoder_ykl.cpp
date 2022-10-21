#include <iostream>
#include <cstdio>
#include <vector>
#define lowbit(x) x & -x
using namespace std;
const int maxn = 2e5 + 50;
int n, m, q, lst[maxn];
long long s[maxn], ans[maxn];
vector<int> v[maxn];
struct node
{
    int id, x, y, z;
} a[maxn];
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        x = x * 10 + (c ^ 48), c = getchar();
    return x * f;
}
inline void add(int x, int k)
{
    while (x <= m)
        s[x] += k, x += lowbit(x);
}
inline long long query(int x)
{
    long long ret = 0;
    while (x)
        ret += s[x], x -= lowbit(x);
    return ret;
}
int main()
{
    n = read(), m = read(), q = read();
    for (int i = 1; i <= q; i++)
    {
        a[i].id = read(), a[i].x = read(), a[i].y = read();
        if (a[i].id == 1)
            a[i].z = read();
        if (a[i].id == 2)
            lst[a[i].x] = i;
        if (a[i].id == 3)
            v[lst[a[i].x]].push_back(i);
    }
    for (int i = 1; i <= q; i++)
    {
        if (a[i].id == 1)
        {
            add(a[i].x, a[i].z);
            add(a[i].y + 1, -a[i].z);
        }
        else if (a[i].id == 2)
        {
            for (int t : v[i])
                ans[t] = a[i].y - query(a[t].y);
        }
        else
        {
            ans[i] += query(a[i].y);
            printf("%lld\n", ans[i]);
        }
    }
    return 0;
}