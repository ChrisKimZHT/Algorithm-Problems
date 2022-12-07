#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int n, cnt;
/* bool row[32], x1[32], x2[32];
void dfs(int x)
{
    if (x == n + 1)
    {
        cnt++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!row[i] && !x1[n - i + x] && !x2[i + x - 1])
        {
            row[i] = true;
            x1[n - i + x] = true;
            x2[i + x - 1] = true;
            dfs(x + 1);
            row[i] = false;
            x1[n - i + x] = false;
            x2[i + x - 1] = false;
        }
    }
} */

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ans[10] = {1, 0, 0, 2, 10, 4, 40, 92, 352, 724};
    while (cin >> n, n)
    {
        /* cnt = 0;
        dfs(1);
        cout << cnt << endl; */
        cout << ans[n - 1] << endl;
    }
    return 0;
}