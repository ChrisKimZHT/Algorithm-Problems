#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110, MAXM = 10010;
int N, M;
int a[MAXN], dp[MAXM];

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    dp[0] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = M; j >= 0; j--)
            dp[j + a[i]] += dp[j];
    cout << dp[M] << endl;
    return 0;
}