#include <bits/stdc++.h>
#define int long long

using namespace std;

int euler(int x)
{
    int ans = x;
    for (int i = 2; i <= x / i; i++)
    {
        if (!(x % i))
        {
            ans = ans / i * (i - 1);
            while (!(x % i))
                x /= i;
        }
    }
    if (x > 1)
        ans = ans / x * (x - 1);
    return ans;
}

void solve()
{
    int N, M;
    cin >> N >> M;
    int ans = 0;
    for (int i = 1; i <= N / i; i++)
    {
        if (!(N % i))
        {
            if (i >= M)
                ans += euler(N / i);
            if (i != N / i && N / i >= M)
                ans += euler(i);
        }
    }
    cout << ans << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}