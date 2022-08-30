#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> cnt;
    while (n--)
    {
        int a;
        cin >> a;
        for (int i = 2; i <= a / i; i++)
            while (!(a % i))
            {
                cnt[i]++;
                a /= i;
            }
        if (a > 1)
            cnt[a]++;
    }
    long long ans = 1;
    for (auto p : cnt)
    {
        ans *= p.second + 1;
        ans %= 1000000007;
    }
    cout << ans << endl;
    return 0;
}