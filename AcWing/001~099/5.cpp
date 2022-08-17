#include <bits/stdc++.h>

using namespace std;

const int MAXV = 2010, MAXNS = 22000;
int v[MAXNS], w[MAXNS], idx;
int dp[MAXV];
int N, V;

int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int t = 1;
        while (c >= t)
        {
            v[++idx] = a * t;
            w[idx] = b * t;
            c -= t;
            t *= 2;
        }
        if (c)
        {
            v[++idx] = a * c;
            w[idx] = b * c;
        }
    }
    for (int i = 1; i <= idx; i++)
    {
        for (int j = V; j > 0; j--)
        {
            if (j >= v[i])
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[V] << endl;
    return 0;
}