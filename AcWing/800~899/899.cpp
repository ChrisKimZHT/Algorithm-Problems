#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> str;
int dp[100][100];

int get_dp(string &A, string &B)
{
    for (int i = 1; i <= A.size(); i++)
    {
        for (int j = 1; j <= B.size(); j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            if (A[i - 1] == B[j - 1])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    return dp[A.size()][B.size()];
}

int get_ans(string &B, int k)
{
    int ans = 0;
    for (auto &A : str)
    {
        if (get_dp(A, B) <= k)
            ans++;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i <= 20; i++)
        dp[i][0] = dp[0][i] = i;
    cin >> n >> m;
    while (n--)
    {
        string tmp;
        cin >> tmp;
        str.push_back(tmp);
    }
    while (m--)
    {
        string tmp;
        int t;
        cin >> tmp >> t;
        cout << get_ans(tmp, t) << endl;
    }
    return 0;
}