#include <bits/stdc++.h>

using namespace std;

inline long long f(long long a, long long b)
{
    return a * a * a + a * a * b + a * b * b + b * b * b;
}

int main(void)
{
    long long N;
    cin >> N;
    long long ans = INT64_MAX;
    long long delta = INT64_MAX;
    for (long long i = 0; i <= 1e6; i++)
    {
        long long l = i, r = 1e6;
        while (l < r)
        {
            long long mid = (l + r) >> 1;
            if (f(i, mid) >= N)
                r = mid;
            else
                l = mid + 1;
        }
        if (f(i, l) - N < delta)
        {
            delta = f(i, l) - N;
            ans = f(i, l);
        }
    }
    cout << ans << endl;
    return 0;
}