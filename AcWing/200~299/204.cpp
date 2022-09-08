#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MAXN = 30;
int n;

LL exgcd(LL a, LL b, LL &x, LL &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    cin >> n;
    LL a1, m1;
    cin >> a1 >> m1;
    for (int i = 2; i <= n; i++)
    {
        LL a2, m2, y1, y2;
        cin >> a2 >> m2;
        LL d = exgcd(a1, a2, y1, y2);
        if ((m2 - m1) % d)
        {
            cout << -1 << endl;
            return 0;
        }
        y1 *= (m2 - m1) / d;
        LL tmp = a2 / d;
        y1 = (y1 % tmp + tmp) % tmp;
        m1 += a1 * y1;
        a1 = a1 / d * a2;
    }
    cout << (m1 % a1 + a1) % a1 << endl;
    return 0;
}