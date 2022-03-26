#include <bits/stdc++.h>
#define SIZE 200010

using namespace std;

long long A[SIZE], candy[SIZE], pre[SIZE];

int main(void)
{
    long long N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        pre[i] = -1;
    candy[0] = 0;
    pre[0] = 0;
    long long rep_beg = 0, rep_end = 0;
    for (long long i = 0; i < N; i++)
    {
        candy[i + 1] = candy[i] + A[candy[i] % N];
        if (pre[candy[i + 1] % N] != -1)
        {
            rep_beg = pre[candy[i + 1] % N];
            rep_end = i + 1;
            break;
        }
        pre[candy[i + 1] % N] = i + 1;
    }
    if (K <= rep_beg)
    {
        cout << candy[K] << endl;
    }
    else
    {
        long long rep_sum = candy[rep_end] - candy[rep_beg];          // 循环部分的和
        long long rep_frq = rep_end - rep_beg;                        // 循环部分的周期
        long long rep_tim = (K - rep_beg) / rep_frq;                  // 循环次数
        long long rep_rmn = (K - rep_beg) % rep_frq;                  // 最后剩余的部分
        long long ans = rep_sum * rep_tim + candy[rep_beg + rep_rmn]; // 结果
        cout << ans << endl;
    }
    return 0;
}