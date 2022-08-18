#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
int N, num[MAXN];
int dp[MAXN];

int main()
{
    num[0] = INT32_MIN;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> num[i];
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < i; j++)
            if (num[j] < num[i])
                dp[i] = max(dp[i], dp[j] + 1);
    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}

/* #include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
int N, num[MAXN];
int dp[MAXN];
int pre[MAXN];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> num[i];
    for (int i = 1; i <= N; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
            if (num[j] < num[i] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                pre[i] = j;
            }
    }
    int ans = 0, mx = 0;
    for (int i = 1; i <= N; i++)
        if (dp[i] > ans)
        {
            ans = dp[i];
            mx = i;
        }
    cout << ans << endl;
    for (int i = mx; i; i = pre[i])
        cout << num[i] << ' ';
    cout << endl;
    return 0;
} */