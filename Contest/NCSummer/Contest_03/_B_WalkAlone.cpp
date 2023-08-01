#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[2][310][310][310];
int solve()
{
    int n, mod;
    cin >> n >> mod;
    // A：阶乘 C：组合数
    vector<int> fac(n * 2 + 3);
    vector<vector<int>> C(n * 2 + 3, vector<int>(n * 2 + 3));
    C[0][0] = fac[0] = 1;
    for (int i = 1; i <= n * 2; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    // 清空
    for (int i = 0; i <= n + 3; i++)
        for (int j = 0; j <= n + 3; j++)
            for (int k = 0; k <= n + 3; k++)
                dp[0][i][j][k] = dp[1][i][j][k] = 0;
    // 快速取模
    function<void(int &, int)> add = [&](int &x, int y)
    {
        if ((x += y) >= mod)
            x -= mod;
    };
    function<void(int &, int)> del = [&](int &x, int y)
    {
        if ((x -= y) < 0)
            x += mod;
    };
    // 任何情况，都能拿走一张牌
    int ans = fac[2 * n];
    // 初始条件：在还没开始抽牌之前，大（[n+1,2n]）还剩n张，小（[1,n]）也剩n张。
    for (int i = 1; i <= n; i++)
    {
        dp[0][n][n][i] = i % mod; // 一开始是小，当前选择的牌是[1,i]范围，有i种
        dp[1][n][n][i] = i % mod; // 一开始是大，同理
    }
    // 枚举大小两类牌在本轮抽取完成后，各剩多少（x,y），倒序枚举
    for (int x = n; x >= 0; x--)
    {
        for (int y = n; y >= 0; y--)
        {
            if (x + y >= 2 * n) // 初值设定过
                continue;
            // 本次抽的是[1,n]中的牌
            for (int k = 1; k <= x; k++)
            {
                if (x != n) // 上一轮抽到一张范围在[1,n]的牌，如果要继续游戏，如果当前抽到k，则上一轮抽出来的牌必须在[1,k]的范围（比当前小）
                    add(dp[0][x][y][k], (dp[0][x + 1][y][x + 1] - dp[0][x + 1][y][k] + mod) % mod);
                if (y != n) // 再枚举当前抽到的是一张大的，这时一定可以接着抽
                    add(dp[0][x][y][k], dp[1][x][y + 1][y + 1]);
                // 能走到当前这一步的状态，都统计一下这一次抽牌对答案的贡献
                add(ans, dp[0][x][y][k] * fac[x + y - 1] % mod);
            }
            // 前缀和一下
            for (int k = 1; k <= x; k++)
                add(dp[0][x][y][k], dp[0][x][y][k - 1]);
            // for (int k = 1; k <= x; k++)
            //     cout << dp[1][x][y][k] << " \n"[k == x];
            // 本次抽到的是[n+1,2n]中的牌
            for (int k = 1; k <= y; k++)
            {
                if (y != n) // 上一轮抽到一张范围在[n+1,2n]的牌，如果要继续游戏，如果当前抽到k，则上一轮抽出来的牌必须在[k+1,y+1]的范围（比当前大）
                    add(dp[1][x][y][k], (dp[1][x][y + 1][y + 1] - dp[1][x][y + 1][k] + mod) % mod);
                if (x != n) // 上一轮抽到一张[1,n]的牌，都可以继续抽牌
                    add(dp[1][x][y][k], dp[0][x + 1][y][x + 1]);
                // 能走到当前这一步的状态，都统计一下这一次抽牌对答案的贡献
                add(ans, dp[1][x][y][k] * fac[x + y - 1] % mod);
            }
            // 前缀和一下
            for (int k = 1; k <= y; k++)
                add(dp[1][x][y][k], dp[1][x][y][k - 1]);
            // for (int k = 1; k <= y; k++)
            //     cout << dp[1][x][y][k] << " \n"[k == y];
        }
    }
    // 全部能抽完的部分多算了一步
    add(ans, (fac[2 * n] - dp[0][1][0][1] - dp[1][0][1][1] + mod) % mod);
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        cout << solve() << "\n";
    return 0;
}
