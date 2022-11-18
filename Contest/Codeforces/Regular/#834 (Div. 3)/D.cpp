#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll cnt_2 = 0, cnt_5 = 0;
    ll nn = n;
    while (!(nn % 2))
    {
        nn /= 2;
        cnt_2++;
    }
    while (!(nn % 5))
    {
        nn /= 5;
        cnt_5++;
    }
    ll t = 1;
    while (cnt_2 < cnt_5 && t * 2 <= m)
    {
        t *= 2;
        cnt_2++;
    }
    while (cnt_5 < cnt_2 && t * 5 <= m)
    {
        t *= 5;
        cnt_5++;
    }
    if (cnt_2 != cnt_5)
    {
        cout << n * (m / t * t) << endl;
        return;
    }
    while (t * 10 <= m)
        t *= 10;
    cout << n * (m / t * t) << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}