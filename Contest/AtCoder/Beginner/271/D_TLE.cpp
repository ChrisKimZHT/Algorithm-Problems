#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;
int N, S;
int a[MAXN], b[MAXN];
bool st[MAXN];

bool dfs(int dep, int rem)
{
    if (dep == N)
        return rem == 0;
    if (rem - a[dep] >= 0)
        if (dfs(dep + 1, rem - a[dep]))
        {
            st[dep] = true;
            return true;
        }
    if (rem - b[dep] >= 0)
        if (dfs(dep + 1, rem - b[dep]))
        {
            st[dep] = false;
            return true;
        }
    return false;
}

int main()
{
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> a[i] >> b[i];
    bool flag = dfs(0, S);
    if (flag)
    {
        cout << "Yes" << endl;
        for (int i = 0; i < N; i++)
            cout << (st[i] ? 'T' : 'H');
        cout << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}