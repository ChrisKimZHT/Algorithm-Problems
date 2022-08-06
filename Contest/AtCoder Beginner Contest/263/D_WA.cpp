#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 2e5 + 10;
int N, L, R;
int A[MAXN];

signed main()
{
    cin >> N >> L >> R;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    int sum = 0, x = 0, de = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += A[i];
        if (sum - i * L > de)
        {
            de = sum - i * L;
            x = i;
        }
    }
    for (int i = 1; i <= x; i++)
        A[i] = L;
    sum = 0, x = 0, de = 0;
    for (int i = N; i >= 1; i--)
    {
        sum += A[i];
        if (sum - (N - i + 1) * R > de)
        {
            de = sum - (N - i + 1) * R;
            x = N - i + 1;
        }
    }
    for (int i = N; i > N - x; i--)
        A[i] = R;
    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans += A[i];
    cout << ans << endl;
    return 0;
}