#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int N, M;
int cnt_w[MAXN], cnt_b[MAXN], cnt_r[MAXN];

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            if (s[j] == 'W')
                cnt_w[i]++;
            else if (s[j] == 'R')
                cnt_r[i]++;
            else
                cnt_b[i]++;
        }
    }
    int ans = INT32_MAX;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int k = N - i - j;
            if (k >= 1)
            {
                int t = 0;
                for (int a = 0; a < i; a++)
                    t += cnt_b[a] + cnt_r[a];
                for (int a = i; a < i + j; a++)
                    t += cnt_r[a] + cnt_w[a];
                for (int a = i + j; a < i + j + k; a++)
                    t += cnt_w[a] + cnt_b[a];
                ans = min(ans, t);
            }
        }
    }
    cout << ans << endl;
    return 0;
}