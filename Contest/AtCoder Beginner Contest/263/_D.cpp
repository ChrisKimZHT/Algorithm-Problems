#include <bits/stdc++.h>

using namespace std;

long long N, L, R;

int main()
{
    cin >> N >> L >> R;
    long long suml = 0, ans = N * R;
    for (int i = 1; i <= N; i++)
    {
        int tmp;
        cin >> tmp;
        suml = min(suml + tmp, L * i);
        ans = min(ans, suml + (N - i) * R);
    }
    cout << ans << endl;
    return 0;
}