#include <bits/stdc++.h>

using namespace std;

inline double f(long long x)
{
    if (x >= 1e7)
        return 2.0;
    else if (x <= 9800000)
        return 1.0 * (x - 9500000) / 3e5;
    else
        return 1.0 + (x - 9800000) / 2e5;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long n;
        double c;
        cin >> n >> c;
        double ans = f(n) + c;
        if (ans < 0)
            ans = 0;
        cout << fixed << setprecision(7) << ans << endl;
    }
    return 0;
}