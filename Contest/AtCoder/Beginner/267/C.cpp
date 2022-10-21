#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 2e5 + 10;
int N, M;
int psA[MAXN];

signed main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> psA[i];
        psA[i] += psA[i - 1];
    }
    int sum = 0, ans = INT64_MIN;
    for (int i = 1; i <= M; i++)
        sum += i * (psA[i] - psA[i - 1]);
    ans = max(ans, sum);
    for (int i = M + 1; i <= N; i++)
    {
        sum -= psA[i - 1] - psA[i - M - 1];
        sum += M * (psA[i] - psA[i - 1]);
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}