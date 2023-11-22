#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 25;
ll ans[MAXN][MAXN][MAXN];

ll w(ll a, ll b, ll c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    if (ans[a][b][c])
        return ans[a][b][c];
    if (a < b && b < c)
        return ans[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    return ans[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main()
{
    ll a, b, c;
    while (cin >> a >> b >> c, ~a || ~b || ~c)
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
    return 0;
}