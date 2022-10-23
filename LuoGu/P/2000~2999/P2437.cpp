#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
vector<int> dp[MAXN];
int m, n;

vector<int> bi_add(vector<int> &a, vector<int> &b)
{
    if (a.size() > b.size())
        return bi_add(b, a);
    vector<int> ans;
    int t = 0;
    for (int i = 0; i < b.size(); i++)
    {
        if (i < a.size())
            t += a[i];
        t += b[i];
        ans.push_back(t % 10);
        t /= 10;
    }
    if (t)
        ans.push_back(1);
    return ans;
}

int main()
{
    cin >> m >> n;
    dp[m].push_back(1);
    for (int i = m + 1; i <= n; i++)
        dp[i] = bi_add(dp[i - 1], dp[i - 2]);
    for (int i = dp[n].size() - 1; i >= 0; i--)
        cout << dp[n][i];
    cout << endl;
    return 0;
}