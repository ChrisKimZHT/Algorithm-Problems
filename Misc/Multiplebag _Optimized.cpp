#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE_NlogS = 25000, SIZE_V = 2010;
int N, V, cnt;
int v[SIZE_NlogS], w[SIZE_NlogS];
int dp[SIZE_V];

int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
    {
        int a, b, s;
        cin >> a >> b >> s;
        int k = 1;
        while (k <= s)
        {
            cnt++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;
        }
        if (s > 0)
        {
            cnt++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = V; j >= v[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[V] << endl;
    return 0;
}