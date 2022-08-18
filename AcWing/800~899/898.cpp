/* #include <bits/stdc++.h>

using namespace std;

const int MAXN = 510, NONE = 0x3f3f3f3f;
int n;
int tri[MAXN][MAXN];
int sum[MAXN][MAXN];

int get(int i, int j)
{
    if (sum[i][j] != NONE)
        return sum[i][j];
    else
    {
        sum[i][j] = max(get(i + 1, j) + tri[i][j], get(i + 1, j + 1) + tri[i][j]);
        return sum[i][j];
    }
}

int main()
{
    memset(sum, 0x3f, sizeof(sum));
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> tri[i][j];
    for (int i = 1; i <= n; i++)
        sum[n][i] = tri[n][i];
    cout << get(1, 1) << endl;
    return 0;
} */

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 510;
int n;
int tri[MAXN][MAXN];
int sum[MAXN][MAXN];
int ans = INT32_MIN;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> tri[i][j];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            sum[i][j] = INT32_MIN;
    sum[1][1] = tri[1][1];
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            sum[i][j] = tri[i][j] + max(sum[i - 1][j - 1], sum[i - 1][j]);
    for (int i = 1; i <= n; i++)
        ans = max(ans, sum[n][i]);
    cout << ans << endl;
    return 0;
}