#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30, MAXT = 2e5;
int m, n;
int arr[MAXN * MAXN];
int mach[MAXN][MAXN], cost[MAXN][MAXN];
int stage[MAXN], finish[MAXN];
bool busy[MAXN][MAXT];

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m * n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mach[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> cost[i][j];
    int ans = 0;
    for (int i = 1; i <= m * n; i++)
    {
        int &type = arr[i];
        int &now_stage = stage[type];
        int &now_finish = finish[type];
        int &now_mach = mach[type][now_stage + 1];
        int &now_cost = cost[type][now_stage + 1];
        int space = 0;
        for (int j = now_finish + 1;; j++)
        {
            if (!busy[now_mach][j])
                space++;
            else
                space = 0;
            if (space >= now_cost)
            {
                for (int k = 0; k < now_cost; k++)
                    busy[now_mach][j - k] = true;
                now_stage = (now_stage + 1) % m;
                now_finish = j;
                break;
            }
        }
        ans = max(ans, now_finish);
    }
    cout << ans << endl;
    return 0;
}