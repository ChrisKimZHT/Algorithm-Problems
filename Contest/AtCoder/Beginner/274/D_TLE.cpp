#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;
const int d[2] = {1, -1};
int N, x, y;
int A[MAXN];

bool dfs(int dep, int pos_x, int pos_y, bool dir)
{
    if (dep > N)
        return pos_x == x && pos_y == y;
    if (dir)
    {
        for (int i = 0; i < 2; i++)
            if (dfs(dep + 1, pos_x + d[i] * A[dep], pos_y, !dir))
                return true;
    }
    else
    {
        for (int i = 0; i < 2; i++)
            if (dfs(dep + 1, pos_x, pos_y + d[i] * A[dep], !dir))
                return true;
    }
    return false;
}

int main()
{
    cin >> N >> x >> y;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    if (dfs(2, A[1], 0, false))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}