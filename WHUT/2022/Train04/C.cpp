#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

struct Triple
{
    int first, second, third;
};

bool cmp(Triple a, Triple b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M, R;
    cin >> N >> M >> R;
    vector<Triple> intv(M);
    for (int i = 0; i < M; i++)
        cin >> intv[i].first >> intv[i].second >> intv[i].third;
    sort(intv.begin(), intv.end(), cmp);
    vector<int> dp(M);
    for (int i = 0; i < M; i++)
    {
        dp[i] = intv[i].third;
        for (int j = 0; j < i; j++)
            if (intv[j].second + R <= intv[i].first)
                dp[i] = max(dp[i], dp[j] + intv[i].third);
    }
    int ans = 0;
    for (int i = 0; i < M; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}