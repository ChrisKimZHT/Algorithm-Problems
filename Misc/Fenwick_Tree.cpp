#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
int Fenwick_Tree[MAXN];

void update(int pos, int val)
{
    for (int i = pos; i < MAXN; i += i & -i)
        Fenwick_Tree[i] += val;
}

int query(int pos)
{
    int ans = 0;
    for (int i = pos; i; i -= i & -i)
        ans += Fenwick_Tree[i];
    return ans;
}

inline int query(int l, int r)
{
    return query(r) - query(l - 1);
}

int main()
{
    cout << "K" << endl;
    update(1, 10);
    update(2, 30);
    cout << query(2) << endl;
    return 0;
}