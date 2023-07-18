#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 30;
int n;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

// first-a second-mod
pair<ll, ll> excrt(pair<ll, ll> a, pair<ll, ll> b)
{
    ll ya, yb;
    ll d = exgcd(a.second, b.second, ya, yb);
    if ((b.first - a.first) % d)
        return {-1, -1};
    ya *= (b.first - a.first) / d;
    ll tmp = b.second / d;
    ya = (ya % tmp + tmp) % tmp;
    a.first += a.second * ya;
    a.second = a.second / d * b.second;
    return a;
}

int main()
{
    cin >> n;
    pair<ll, ll> a;
    cin >> a.second >> a.first;
    for (int i = 2; i <= n; i++)
    {
        pair<ll, ll> b;
        cin >> b.second >> b.first;
        a = excrt(a, b);
    }
    if (a.first == -1)
        cout << -1 << endl;
    else
        cout << (a.first % a.second + a.second) % a.second << endl;
    return 0;
}