#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 50;
int N, a[MAXN], b[MAXN], idx = 1;

void read_tree(int v)
{
    if (v > N)
        return;
    read_tree(2 * v);
    read_tree(2 * v + 1);
    b[v] = a[idx++];
}

void solve()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    read_tree(1);
    for (int i = 1; i <= N; i++)
        cout << b[i] << " \n"[i == N];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}