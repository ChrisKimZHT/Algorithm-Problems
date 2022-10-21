#include <bits/stdc++.h>
#define int long long

using namespace std;

const int SIZE = 2e5 + 10;
const int MAXN = 2e5;
int N;
int num_cnt[SIZE];

signed main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        num_cnt[tmp]++;
    }
    int ans = 0;
    for (int i = 1; i <= MAXN; i++)
    {
        if (!num_cnt[i])
            continue;
        for (int j = 1; j <= MAXN; j++)
        {
            if (i * j > MAXN)
                break;
            if (!num_cnt[j])
                continue;
            if (num_cnt[i * j])
            {
                ans += num_cnt[i] * num_cnt[j] * num_cnt[i * j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}