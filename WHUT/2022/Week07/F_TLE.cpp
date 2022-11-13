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

const int MAXN = 1e6 + 10;
int ans[MAXN];

signed main()
{
    for (int i = 2; i < MAXN; i++)
        ans[i] = ans[i - 1] + euler(i);
    int n;
    while (cin >> n, n)
        cout << ans[n] << endl;
    return 0;
}