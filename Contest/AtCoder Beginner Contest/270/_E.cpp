#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
long long N, K, A[MAXN];

long long eat(long long num)
{
    long long ans = 0;
    for (int i = 0; i < N; i++)
        ans += min(A[i], num);
    return ans;
}

long long get_lap(long long l, long long r)
{
    while (l + 1 < r)
    {
        long long mid = (l + r) / 2;
        if (eat(mid) <= K)
            l = mid;
        else
            r = mid;
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    long long lap = get_lap(0, K);
    long long remain = K - eat(lap);
    for (int i = 0; i < N; i++)
    {
        if (!remain)
        {
            cout << max(A[i] - lap, 0LL) << ' ';
            continue;
        }
        if (A[i] - lap - 1 >= 0)
            remain--;
        cout << max(A[i] - lap - 1, 0LL) << ' ';
    }
    cout << endl;
    return 0;
}